#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<iostream>

int main(int argc,char* argv[])
{
  if(argc!=3){
    std::cout<<"Usage:./tcp_server IP port"<<std::endl;
    return -1;
  }
  std::string ip = argv[1];
  uint16_t port = atoi(argv[2]);

  // create socket 
  
  int sockfd = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
  if(sockfd<0){
    perror("socket creatr error");
    return -2;
  }
 
  // 向服务端发起链接请求
  struct sockaddr_in srv_addr;
  srv_addr.sin_family = AF_INET;
  srv_addr.sin_addr.s_addr = inet_addr(ip.c_str());
  srv_addr.sin_port = htons(port);
  socklen_t len = sizeof(struct sockaddr_in);

  int ret = connect(sockfd,(struct sockaddr*)&srv_addr,len);
  if(ret < 0){
    perror("connect error");
    return -3;
  }

  while(1){
    //向服务端发送数据
    char buf[1024] = {0};
    std::cout<<"Client:";
    fflush(stdout);
    std::cin>>buf;
    ret = send(sockfd,buf,sizeof(buf),0);
    if(ret<0){
      std::cout<<"send error"<<std::endl;
      continue;
    }

    //接收服务端的数据
    memset(buf,0,1024);
    ret = recv(sockfd,buf,1024,0);
    if(ret<0){
      std::cout<<"peer shutdown"<<std::endl;
      continue;
    }
    std::cout<<"Server:";
    std::cout<<buf<<std::endl;
  }

  //关闭套接字
  close(sockfd);
  sockfd = -1;
  return 0;
}
