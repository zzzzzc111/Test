#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
  int ret = fork();
  if(ret < 0){
    perror("fork error");
    return 1;
  }
  if(ret == 0){
    printf("I am child: %d, ret: %d\n",getpid(),ret);
  }
  else{
    printf("I am father: %d, ret: %d\n",getpid(),ret);
  }
  sleep(1);
  return 0;
}
