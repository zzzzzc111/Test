#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<sched.h>

int ticket = 100;
pthread_mutex_t mutex;

void *route(void* arg)
{
  char* id = (char*)arg;
  while(1){
    usleep(1000);
    pthread_mutex_lock(&mutex);
    if(ticket>0){
      printf("%s sells ticket: %d\n",id,ticket);
      ticket--;
      pthread_mutex_unlock(&mutex);
    }
    else {
      pthread_mutex_unlock(&mutex);
      break;
    }
  }
}

int main(){
  pthread_t tid1,tid2,tid3,tid4;
  pthread_mutex_init(&mutex,NULL);

  pthread_create(&tid1,NULL,route,"thread1");
  pthread_create(&tid2,NULL,route,"thread2");
  pthread_create(&tid3,NULL,route,"thread3");
  pthread_create(&tid4,NULL,route,"thread4");

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);
  pthread_join(tid3,NULL);
  pthread_join(tid4,NULL);

  pthread_mutex_destroy(&mutex);
}
