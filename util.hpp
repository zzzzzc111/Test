#pragma once 
#include<cstdlib>
#include<iostream>
#include<stdint.h>
#include<sys/time.h>
#include<string>
#include<fstream>
//准备一个时间戳获取工具

class TimeUtil{
public:
  //获取当前的时间戳
  static int64_t TimeStamp(){
    struct timeval tv;
    ::gettimeofday(&tv,NULL);
    return tv.tv_sec;
    //return tv.tv_set * 1000 + tv.tv_usec / 1000 返回微秒级时间戳
  }
  static int64_t TimeStampMS(){
    struct timeval tv;
    ::gettimeofday(&tv,NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
  } 
};

//打印日志的工具
//期望打印出的日志格式形如：
//[I1550892581 util.hpp:31] hello
//日志的使用方式形如
//LOG(INFO)<<"hello"<<"\n";
//日志的级别。
//FATAL 致命的
//ERROR 错误
//WARNING 警告
//INFO 提示
enum Level{
  INFO,
  WARNING,
  ERROR,
  FATAL,
};

inline std::ostream& Log(Level level,const std::string& file_name,int line_num){
  std::string prefix = "[";
  if(level == INFO){
    prefix += "I";
  }
  else if(level == WARNING){
    prefix += "W";
  }
  else if(level == ERROR){
    prefix += "E";
  }
  else if(level == FATAL){
    prefix += "F";
  }
  prefix += std::to_string(TimeUtil::TimeStamp());
  prefix += " ";
  prefix += file_name;
  prefix += ":";
  prefix += std::to_string(line_num);
  prefix += "] ";
  std::cout<<prefix;
  return std::cout;
}

#define LOG(level) Log(level,__FILE__,__LINE__)

//准备一下文件相关工具类
class FileUtil{
  public:
    //传入一个文件路径，帮我们把文件的所有内容都读出来放到content字符串中
    //输入型参数const引用
    //输出型参数 指针
    //输入输出型参数 引用
    static bool Read(const std::string& file_path,std::string* content){
      content->clear();
      std::ifstream file(file_path.c_str());
      if(!file.is_open()){
        return false;
      }

      std::string line;
      while(std::getline(file,line)){
        *content += line + "\n";
      }
      file.close();
      return true;
    }

    static bool Write(const std::string& file_path,const std::string& content){
      std::ofstream file(file_path.c_str());
      if(!file.is_open()){
        return false;
      }
      file.write(content.c_str(),content.size());
      file.close();
      return true;
    }

};

