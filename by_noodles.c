#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

int have_noodle = 0;
pthread_cond_t sale;
pthread_cond_t eat;
pthread_mutex_t mutex;

void* sale_noodle(void* arg)
{
  while(1){
    pthread_mutex_lock(&mutex);
    if(have_noodle == 1){
      pthread_cond_wait(&sale,&mutex);
    }
    printf("create noodle!!\n");
    have_noodle = 1;
    pthread_cond_signal(&eat);
    pthread_mutex_unlock(&mutex);
  }
  return NULL;
}

void* eat_noodle(void* arg)
{
  while(1){
    pthread_mutex_lock(&mutex);
    if(have_noodle == 0){
      pthread_cond_wait(&eat,&mutex);
    }
    printf("eat noodle!! good!!\n");
    have_noodle = 0;
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&sale);
  }
  return NULL;
}

int main()
{
  pthread_t tid1,tid2;
  int ret;

  pthread_cond_init(&sale,NULL);
  pthread_cond_init(&eat,NULL);
  pthread_mutex_init(&mutex,NULL);

  ret = pthread_create(&tid1,NULL,sale_noodle,NULL);
  if(ret!=0){
    printf("create thread error\n");
    return -1;
  }

  ret = pthread_create(&tid2,NULL,eat_noodle,NULL);
  if(ret!=0){
    printf("create thread error\n");
    return -1;
  }

  pthread_join(tid1,NULL);
  pthread_join(tid2,NULL);

  pthread_cond_destroy(&sale);
  pthread_cond_destroy(&eat);
  pthread_mutex_destroy(&mutex);

  return 0;
}
