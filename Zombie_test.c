#include<stdio.h>
#include<stdlib.h>

int main()
{
  pid_t id = fork();
  if(id<0){
    perror("fork error");
    return 1;
  }
  else if(id>0){
    printf("parent[%d] is in sleep!\n",getpid());
    sleep(30);
  }
  else if(id == 0){
    printf("child[%d] is being zombie!\n",getpid());
    sleep(5);
    exit(EXIT_FAILURE);
  }
  return 0;
}




