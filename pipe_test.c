#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
  int fds[2];
  char buf[100];
  int len;

  if(pipe(fds) == -1){
    perror("make pipe error");
  }

  //read from stdin
  while(fgets(buf,100,stdin)){
    len = strlen(buf);
    //write into pipe 
    if(write(fds[1],buf,len)!=len){
      perror("wiite to pipe");
      break;
    }
    memset(buf,0x00,sizeof(buf));

    //read from pipe 
    if((len = read(fds[0],buf,100))==-1){
      perror("read from pipe");
      break;
    }

    //write to stdout 
    if(write(1,buf,len)!=len){
      perror("write to stdout");
      break;
    }
  }
}
