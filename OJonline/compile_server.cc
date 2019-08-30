#include<unordered_map>
#include"httplib.h"
#include"compile.hpp"
#include<jsoncpp/json/json.h>

int main(){
  using namespace httplib;
  Server server;
  //Get 注册了一个回调函数 这个函数调用时机，处理Get方法的时候
  //lambda表达式？  匿名函数
  //[](){}   []告诉这是lanbda表达式  ()参数列表
  server.Post("/compile",[](const Request& req,Response& resp){
    //根据具体的场景 根据请求 计算出响应结果
   (void)req;
   //  如何从req中获取到JSON请求 JSON如何和HTTP协议结合，
   
   //JSON如何进行解析和构造  json.cpp第三方库
   //需要的请求格式是JSON格式 而HTTP能够提供的格式是另外一种键值对的格式 所以此处要进行格式的转换
   //此处由于提交的代码中可能会包含一些特殊符号 这些特殊符号要想正确传输就需要进行转义 浏览器自动帮我们完成
   //然后解析这个数据 然后整理成我们需要的json格式 然后解析这个数据整理成需要的json格式
   //键值对 用哪个数据结构表示？  STL中的容器
   std::unordered_map<std::string,std::string> body_kv;
   UrlUtil::ParseBody(req.body,&body_kv);

   //在这里调用CompileAndRun
   Json::Value req_json;    //从req对象中获取到
   //for(std::unordered_map<std::string,std::string>::iterator it = body_kv.begin();it != body_kv.end();++it){
   //req_json[it->first] = it->second;
   //}
   for(auto p : body_kv){
   //p的类型和 *it 得到的类型是一致的
   req_json[p.first] = p.second;
   }

   Json::Value resp_json;  //resp_json 放到响应中
   Compiler::CompilAndRun(req_json,&resp_json);
   //需要把Json::Value对象序列化成一个字符串 才能返回
   Json::FastWriter write;
   resp.set_content(write.write(resp_json),"text/plain");
   });
  //加上这个目录是为了让浏览器能够访问到一个静态页面
  //静态页面：index.html不会发生变化
  //动态页面：编译结果随着参数的不同而发生变化
  server.set_base_dir("./wwwroot");
  server.listen("0.0.0.0",9092);
  return 0;  
}
