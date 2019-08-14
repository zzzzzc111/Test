#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define BACKLOG 5   //最大并发连接数

int main(int argc,char* argv[])
{
  if(argc!=3){
    std::cout<<"Usag:./tcp_server IP port"<<std::endl;
    return -1;
  }

  std::string ip = argv[1];
  uint16_t port = atoi(argv[2]);

  //第一部 创建套接字
  int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(sockfd<0){
    perror("socket create error");
    return -2;
  }
  std::cout<<"create socket success..."<<std::endl;

  //第二步：为套接字绑定地址信息
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip.c_str());
  addr.sin_port = htons(port);
  socklen_t len = sizeof(struct sockaddr_in);
  int ret = bind(sockfd,(struct sockaddr*)&addr,len);
  if(ret<0){
    perror("bind error");
    return -3;
  }
  std::cout<<"bind success"<<std::endl;

  //第三步：开始监听
  ret = listen(sockfd,BACKLOG);
  if(ret<0){
    perror("listen error");
    return -4;
  }

  std::cout<<"listen success"<<std::endl;
  while(1)
  {
  //第四步：接收客户端的连接请求
    struct sockaddr_in cli_addr;
    len = sizeof(struct sockaddr_in);
    int newsockfd = accept(sockfd,(struct sockaddr*)&cli_addr,&len);
    if(newsockfd<0){
      std::cout<<"accept error"<<std::endl;
      continue;
    }
  

    //第五步：接收客户端的数据
    char buf[1024] = {0};
    ret = recv(newsockfd,buf,1024,0);
    if(ret<0){
      std::cout<<"recv error"<<std::endl;
      continue;
    }
    else if(ret == 0){
      std::cout<<"peer shutdown"<<std::endl;
      continue;
    }
    std::cout<<"Client:";
    std::cout<<buf<<std::endl;

    //第六步：向客户端发送数据
    memset(buf,0,1024);
    std::cout<<"Server:";
    fflush(stdout);
    std::cin>>buf;
    ret = send(newsockfd,buf,sizeof(buf),0);
    if(ret < 0){
      std::cout<<"send error"<<std::endl;
      continue;
    }
  }
  //第七步：关闭套接字
  close(sockfd);
  sockfd = -1;
  return 0;
}


