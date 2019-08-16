#pragma once 
//1.C/C++标准库文件
#include<string>
#include<atomic>
//2.操作系统头文件
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
//3.第三方库头文件
#include<jsoncpp/json/json.h>
//4.当前项目的其他文件
#include"util.hpp"

//此代码完成在线编译模块的功能
//提供一个Compiler类 由这个类提供一个核心的CompileAndRun函数 由这个函数来完成编译+运行的功能

class Compiler{
  public:
    //此处看到的参数和返回结果 形如画图板上的JSON格式
    //Json::Value类jsoncpp中的核心类 借助这个类就可以完成序列化和反序列化的动作
    //这个类的使用方法 和map非常相似 可以使用[] 完成属性的操作
    
    //本质上此处是使用文件来完成进程间通信
    //1.源代码文件 name表示当前请求的名字 请求和请求之间 name必须是不相同的
    //形如：tmp_1550976161.1.cpp       tmp_1550976161.2.cpp
    static std::string SrcPath(const std::string& name){
      return "./temp_files/"+ name + ".cpp";
    }
    //2.编译错误文件
    static std::string CompileErrorPath(const std::string& name){
      return "./temp_files/" + name + ".compile_error";
    }
    //3.可执行程序文件
    static std::string ExePath(const std::string& name){
      return "./temp_files/" + name + ".exe";
    }
    //4.标准输入文件
    static std::string StdinPath(const std::string& name){
      return "./temp_files/" + name + ".stdin";
    }
    //5.标准输出文件
    static std::string StdoutPath(const std::string& name){
      return "./temp_files/" + name + ".stdout";
    }
    //6.标准错误文件
    static std::string StdErrPath(const std::string& name){
      return "./temp_files/" + name + ".stderr";
    }

    static bool CompilAndRun(const Json::Value& req,Json::Value* resp){
      //1.根据请求对象 生成源代码文件 和标准输入文件
      if(req["code"].empty()){
        (*resp)["error"] = 3;
        (*resp)["reason"] = "code empty";
        LOG(ERROR) << "code empty" << std::endl;
        return false;
      }
      //req["code"] 根据 key 取出value 。 value类型也是JSON::Value.这个类型通过asString()转成字符串
      const std::string& code = req["code"].asString();
      //通过这个函数完成把代码写到代码文件中的过程
      std::string file_name = WriteTmpFile(code,req["code"].asString());
      //2.调用g++进行编译(fork + exec / system).
      //  生成可执行程序.如果编译出错 需要把编译错误记录下来(重定向到文件中)
      bool ret = Compile(file_name);
      if(!ret){
        //错误处理
        (*resp)["error"] = 1;
        std::string reason;
        FileUtil::Read(CompileErrorPath(file_name),&reason);
        (*resp)["reason"] = reason;
        //虽然是编译出错 这样的错误是用户自己的错误 不是服务器的错误 对于服务器来说这样的编译出错不是错误
        LOG(INFO)<<"Compile failed!"<<std::endl;
        return false;
      }
      //3.调用可执行程序，把标准输入记录到文件中 然后把文件中的内容重定向给可执行程序，可执行程序的标准输出和标准错误也要重定向输出到文件中
      int sig = Run(file_name);
      if(sig != 0){
        //错误处理
        (*resp)["error"] = 2;
        (*resp)["reason"] = "Program exit by singo: "+ std::to_string(sig);
        LOG(INFO)<<"Program exit by signo: "<<std::to_string(sig)<<std::endl;
        return false;
      }
      //4.把程序的最终结果进行返回 构造 resp 对象
      (*resp)["error"] = 0;
      (*resp)["reason"] = "";
      std::string str_stdout;
      FileUtil::Read(StdoutPath(file_name),&str_stdout);
       (*resp)["stdout"] = str_stdout;
      
      std::string str_stderr;
      FileUtil::Read(StdErrPath(file_name),&str_stderr);        
      (*resp)["stderr"] = str_stderr;
      LOG(INFO)<<"Programe"<<file_name<<" Done"<<std::endl;
      return true;
    }

private:
      //1.把代码写到文件里
      //2.给这次请求分配一个唯一的名字 通过返回值返回
      //  分配的名字形如 tmp_1550976161.2
      static std::string WriteTmpFile(const std::string& code,const std::string& str_stdin){
        //原子操作依赖CPU的支持
        static std::atomic_int id(0);  
        ++id;
        std::string file_name = "tmp_" + std::to_string(TimeUtil::TimeStamp())+"."+std::to_string(id);
        
        FileUtil::Write(SrcPath(file_name),code);
        FileUtil::Write(StdinPath(file_name),str_stdin);
        return file_name;
      }

      static bool Compile(const std::string& file_name){
        //1.先构造出编译指令 g++ file_name.cpp -o file_name.exe -std=c++11
        char* command[20] = {0};
        char buf[20][50] = {{0}};
        for(int i = 0;i < 20;++i){
          command[i] = buf[i];
        }
        //必须保证command的指针都是指向有效内存
        sprintf(command[0],"%s","g++");
        sprintf(command[1],"%s",SrcPath(file_name).c_str());
        sprintf(command[2],"%s","-o");
        sprintf(command[3],"%s",ExePath(file_name).c_str());
        sprintf(command[4],"%s","-std=c++11");
        command[5] = NULL;
        //2.创建子进程
        int ret = fork();
        if(ret > 0){
        //3.父进程进行进程等待
        waitpid(ret,NULL,0);
        }
        else {
        //4.子进程进行程序替换
        int fd = open(CompileErrorPath(file_name).c_str(),O_WRONLY | O_CREAT,0666);
        if(fd < 0){
          LOG(ERROR) << "open Compile file error" << std::endl;
          exit(1);
        }
        dup2(fd,2);  //期望得到的效果是写2能够把数据放到文件中
        execvp(command[0],command);
        //此处子进程执行失败 就直接退出
        exit(0);
        }
        //代码执行到这 如何判断编译是否成功   判定可执行文件是否存在  stat(ls指令是基于stat实现的)
        struct stat st;
        ret = stat(ExePath(file_name).c_str(),&st);
        if(ret < 0){
          //stat执行失败 说明文件不存在
          LOG(INFO) << "Compile failed!" << file_name << std::endl;
          return false;
        }
        LOG(INFO) << "Compile" << file_name << " OK!"  << std::endl;
        return true;
      }

      static int Run(const std::string& file_name){
        //1.创建子进程
        int ret = fork();
        if(ret > 0){
        //2.父进程进行等待
        int status = 0;
        waitpid(ret,&status,0);
        return status & 0x7f;
        }
        else {
        //3.进行重定向(标准输入 标准输出 标准错误)
        int fd_stdin = open(StdinPath(file_name).c_str(),O_RDONLY);
        dup2(fd_stdin,0);
        int fd_stdout = open(StdoutPath(file_name).c_str(),O_WRONLY | O_CREAT,0666);
        dup2(fd_stdout,1);
        int fd_stderr = open(StdErrPath(file_name).c_str(),O_WRONLY | O_CREAT,0666);
        dup2(fd_stderr,2);
        //4.子进程进行程序替换
          execl(ExePath(file_name).c_str(),ExePath(file_name).c_str(),NULL);
          exit(0);
        }
      }
};
