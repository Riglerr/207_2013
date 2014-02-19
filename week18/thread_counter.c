#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//mutex example with threads

//Make 10 threads, each will show current value of a coutner after
//incrementing it. Mutex is needed to ensure we don't have another
//thread change the value after we've incremented it and before we've
//displayed it

void *count_thread( void *ptr );
int val=0;
pthread_mutex_t mx = PTHREAD_MUTEX_INITIALIZER; 

int main(int argc,char* argv[]){
  int num=10;
  pthread_t threads[num];
  int vals[num];
  for(int i=0;i<num;i++){
    vals[i]=i;
    pthread_create( 
		   &threads[i], 
		   NULL,
		   count_thread,
		   (void*) &vals[i]
		   );
  }
  for(int i=0;i<num;i++){
    pthread_join( threads[i], NULL);
  }

  return 0;
}

void *count_thread( void *ptr ){
  //Following line and the one following (&&) to enable mutex assurance when uncommented
  //pthread_mutex_lock(&mx);

  val++;

  //Try with a delay between
  //setting and displaying
  //to highlight the problem 
  //of inconsistency without
  //some kind of mutual exclusion
  //sleep(1);

  printf("Val:%d\tID:%d\n",val,*((int*)(ptr)));

  //(&&)
  //pthread_mutex_unlock(&mx);
}
