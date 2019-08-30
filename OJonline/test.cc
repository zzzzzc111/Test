
#include<jsoncpp/json/json.h>
#include"util.hpp"
#include"compile.hpp"

int main()
{
  Json::Value req;
  req["code"] = "#include<stdio.h>\n  int main() {printf(\"hehe\");  return 0;}";
  req["stdin"] = "";
  Json::Value resp;
  Compiler::CompilAndRun(req,&resp);
  Json::FastWriter write;
  LOG(INFO) << write.write(resp) << std::endl;
  return 0;
}
