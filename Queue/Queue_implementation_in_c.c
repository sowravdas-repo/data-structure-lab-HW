/* Queue data structure ->FIFO(first in first out)
to implement queue we need a front,top,size and dynamic array
here,enqueue means inserting at the top,dequeue deleting from the front
but,linaer queue if we delete(dequeue) an element it never dispper completly
the front just sifted toward top ,so we cann't reuse that memory, that swhy 
we use circular Queue
.BUT HERE IS THE BASIC IMPLEMENTATION IF LINEAR QUEUE
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int front;
    int top;
    int size;
    int *parr;
}queue;

queue *createQueue(int sz){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    q->top=-1;
    q->size=sz;
    q->parr=(int*)calloc(sz,sizeof(int));
    return q;
}

int is_empty(queue *q){
    return (q->front==-1);
}

int is_full(queue *q){
    return (q->top==q->size-1);
}
void enqueue(queue *q,int x){
    if(is_full(q)){
       printf("Queue is full\nQueue overflow !!");
       return;
    }
    if(q->front==-1) q->front++;
    q->top++;
    //(*q).top++;
    q->parr[q->top]=x; //inseert at the end
    //(*q).parr[(*q).top]=x;
}

int dequeue(queue *q){
    if(is_empty(q) || (*q).front > (*q).top){
        printf("\nQueue is empty\nQueue underflow !!");
        return -1;
    }
    int x=q->parr[q->front];
    q->front++;
    if(q->front > q->top){
        q->front=-1;
        q->top=-1;
    }
    return x;
}

void display(queue *q){
    if(is_empty(q)){
        printf("queue is empty\n");
        return;
    }
    for(size_t i=q->front;i<=q->top;i++){
        printf("%d ",*(q->parr+i));
    }
    printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
   queue *q1=createQueue(n);
//    enqueue(q1,10);
//    printf("%d ",q1->parr[q1->front]);
//    enqueue(q1,20);
//    printf("%d ",q1->parr[q1->front]);
for(int i=0;i<n;i++){
    //scanf("%d",&q1->parr[i]);
   // scanf("%d",(*q1).parr+i);
   int x;
   scanf("%d",&x);
   enqueue(q1,x);
}
display(q1);
dequeue(q1);
display(q1);
dequeue(q1);
display(q1);
dequeue(q1);
display(q1);
//notice how instert happeing at the top(at the end)
//and delete heppening form the front 
//that s the queue data structure first comes,first serve
  
    return 0;
}