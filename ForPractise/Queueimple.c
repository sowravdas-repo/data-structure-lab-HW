#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int front;
    int top;
    int size;
    int *p;
}queue;
queue *create(int sz){
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
    return (q->top==q->size-1);
}
void enqueue(queue *q,int val){
    if(is_full(q)){
       printf("Queue is full !! queue overflow\n");
       return;
    }
    if(q->front==-1) q->front=0;
    q->top++;
    q->p[q->top]=val;
}
int dequeue(queue *q){
    if(is_empty(q)){
        printf("queue underflow\n");
        return -1;
    }
    int temp=q->p[q->front];
    q->front++;
    return temp;

}
void display(queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return;
    }
    for(int i=q->front;i<=q->top;i++) printf("%d ",q->p[i]);
    printf("\n");
}
int main(){
    queue *q1=create(4);
    // enqueue(q1,10);
    // printf("%d\n",q1->p[q1->top]);
    // enqueue(q1,100);
    // printf("%d\n",q1->p[q1->top]);
    // enqueue(q1,1000);
    // printf("%d\n",q1->p[q1->top]);
    // printf("%d\n",q1->p[q1->front]);
    // dequeue(q1);
    //  printf("%d\n",q1->p[q1->front]);
    for(int i=0;i<4;i++){
        int x; scanf("%d",&x);
        enqueue(q1,x);
    }
    display(q1);
    dequeue(q1);
    display(q1);
    dequeue(q1);
    display(q1);
    dequeue(q1);
    display(q1);
    return 0;
}