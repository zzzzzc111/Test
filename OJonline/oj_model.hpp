//model?  模型
//MVC(经典的软件设计方式 20年前就有了 现在任然广泛使用)
//现在还有一些更先进的方式比如 MVVM
//M => model:负责数据存储
//V => view:负责显示界面
//C => controller：核心业务逻辑
//
//基于文件的方式完成题目的存储
//约定每一个题目对应一个目录 目录的名字就是题目的ID
//目录里面包含以下几个文件：
//1)header.cpp 代码框架
//2)tail.cpp 代码测试用例
//3)desc.txt 题目详细描述
//除此之外 在搞一个oj_config.cfg文件 作为一个总的入口文件 这个文件是一个行文本文件。这个文件的每一行对应一个需要被服务器加载起来的题目
//这一行里面包含以下几个信息：题目的id 题目的名字 题目的难度 题目对应的目录
#pragma once 
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<fstream>
#include"util.hpp"
//model这个模块要做的事就是把刚才在文件中存储的题目信息加载起来 供服务器随时使用

struct Question{
  std::string id;
  std::string name;
  std::string dir;   //题目对应的目录 目录就包含了题目描述/题目的代码框架/题目的测试用例
  std::string star;  //表示难度

  //以下字段要根据dir字段来获取到
  std::string desc;  //题目的描述
  std::string header_cpp;  //题目的代码框架中的代码
  std::string tail_cpp;    //题目的测试用例代码
};

//完善OJModel类 实现以下的基本操作
class OJModel{
  private:
    //MD5
    //SHA1
    //1.计算的哈希值非常均匀(两个字符串哪怕只差一个字符 计算得到的哈希值也会差别很大)
    //2.不可逆(通过字符串算哈希值很容易 但是给哈希值找到对应的原串 理论上是不可能的)
    //3.固定长度(不管字符串多长 得到的哈希值都是固定长度)
    std::map<std::string,Question> model_;
  public:
    
    //把文件上的数据加载起来 加载到内存中  加到哈希表中
    bool Load(){
      //1.先打开 oj_config.cfg文件
      std::ifstream file("./oj_data/oj_config.cfg");
      if(!file.is_open()){
        return false;
      }
      
      //按行读取 oj_config.cfg文件 并且解析
      std::string line;
      while(std::getline(file,line)){
      //3.根据解析结果拼装成 Question 结构体
        std::vector<std::string> tokens;
        StringUtil::Split(line,"\t",&tokens);
        if(tokens.size() != 4){
          LOG(ERROR) << "config file format error!\n";
          continue;
        }
      //4.把结构体加入到哈希表中
      Question q;
      q.id = tokens[0];
      q.name = tokens[1];
      q.star = tokens[2];
      q.dir = tokens[3];
      FileUtil::Read(q.dir + "/desc.txt", &q.desc);
      FileUtil::Read(q.dir + "/header.cpp", &q.header_cpp);
      FileUtil::Read(q.dir + "/tail.cpp", &q.tail_cpp);
      model_[q.id] = q;
      
      }
      file.close();
      LOG(INFO) << "Load" << model_.size() << "questions\n";
      return true;
    }

    bool GetAllQuestions(std::vector<Question>* questions) const {
      //遍历哈希表就行了
      //auto推导出的类型是一个键值对 push_back需要的类型是Question
      questions->clear();
      for(const auto& kv : model_){          //加const是引用  不加是值拷贝
        questions->push_back(kv.second);
      }
      return true;
    }

    bool GetQuestion(const std::string& id,Question* q) const {
      auto pos = model_.find(id);
      if(pos == model_.end()){
       //该id未查到
       return false;
      }
      *q = pos->second;
      return true;
    }   
};
