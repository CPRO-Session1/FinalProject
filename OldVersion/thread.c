#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

int keepSayingHi = 1;
void* thread1(){
    int start = time(0);
    while(keepSayingHi){
        if(time(0) - start >= 1){
            printf("hi\n");
            start = time(0);
        }
    }
}

void* thread2(){
    int num;
    scanf("Exit %d", &num);
    printf("Exiting\n");
    keepSayingHi = 0;
}

int main(){
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread1, NULL);
    pthread_create(&tid2, NULL, thread2, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}
