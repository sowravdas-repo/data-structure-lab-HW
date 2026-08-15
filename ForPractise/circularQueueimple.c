#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int front;
    int top;
    int size;
    int *p;
}queue;

queue *createQueue(int sz){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    q->top=-1;
    q->size=sz;
    q->p=(int*)malloc(sizeof(int)*sz);
    return q;
}
int is_empty(queue *q){
    return (q->front==-1);
}
int is_full(queue *q){
    return ((q->top+1)%q->size==q->front);
}
void enqueue(queue *q,int val){
    if(is_full(q)){
        printf("Queue is full \n Queue Overflow");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->top=0;
    }
    else{
        q->top=(q->top+1)%q->size;
    }
    q->p[q->top]=val;
}
int dequeue(queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return -1;
    }
    int temp=q->p[q->front];
     if(q->front==q->top){
        q->front=-1;
        q->top=-1;
    }
   else{
      q->front=(q->front+1)%q->size;
   }
    return temp;
}
void display(queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return;
    }
    for(int i=q->front;i!=q->top;i=(i+1)%q->size){
        printf("%d ",q->p[i]);
    }
    printf("%d ",q->p[q->top]);
    printf("\n");
}
void freequeue(queue *q){
    free(q->p);
    free(q);
}
int main(){
    int n; scanf("%d",&n);
   queue *q1=createQueue(n);
   for(int i=0;i<n;i++){
     int x; scanf("%d",&x);
     enqueue(q1,x);
   }
   display(q1);
   dequeue(q1);
   display(q1);
   freequeue(q1);
    return 0;
}