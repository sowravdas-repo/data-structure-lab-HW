#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int front;
    int top;
    int size;
    int *p;
}queue;
queue *createqueue(int sz){
    queue *q=(queue*)malloc(sizeof(queue));
    q->top=-1;
    q->front=-1;
    q->size=sz;
    q-p=(int*)malloc(sizeof(int)*sz);
    return q;
}

int main(){
    return 0;
}