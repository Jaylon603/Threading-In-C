//Practice creating threads in C
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

 

void *resource1(void *arg){
    int tid = *(int*)arg;
    //mutex
    printf("Thread %d:Job started in resource1..\n",tid);
    sleep(1);
    printf("Thread %d: Trying to get resource2\n",tid);
    //mutex
    printf("--->Thread %d: Aquired resource2\n", tid);
    //mutex
    printf("Thread %d:Job finished in resource1..\n",tid);
    //mutex
    sleep(3);
    pthread_exit(NULL);

}

void *resource2(void *arg){
    int tid = *(int*)arg;
    sleep(2);
    //mutex
    printf("Thread %d:Job started in resource2..\n",tid);
    sleep(1);
    printf("Thread %d: Trying to get resource1\n",tid);
    //mutex
    printf("--->Thread %d: Aquired resource1\n",tid);
    //mutex
    printf("Thread %d:Job finished in resource2..\n",tid);
    //mutex
    sleep(3);
    pthread_exit(NULL);

}

 

int main() {

    //create 100 threads; 
    //prime numbered threads accessing resource1
    //every 5th thread accessing resource2
    pthread_t t[100];
    int tids[100];
    int count = 0;
    while(count<100){
        resource1(t);
        count+=1;
    }
    

    //wait for all threads to complete
    return 0;

}