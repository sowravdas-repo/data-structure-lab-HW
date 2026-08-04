/*
In linaer queue after dequeue we cann't reused the memory we left ,this 
problem solved by circular queue ,it is same as linaer queue almost .BUT
it circle around its front ,top with each enqueue(insertion at the back(top))
and dequeue(delete form the front) ,it circle aroud by a veru simple formula
in enqueue as front stays fiexed ,top=(top+1)%size ,so if top is at the end 
after dequeue it should moved to the index 0,so we can reused that inedex
same for front keept track of front by circulating front=(front+1)%size
thats ,the basic of corcular queue
IMLEMENTATION OF CIRCULAR QUEUE DATA STRUCTURE USING C
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
    (*q).top=-1;
    q->size=sz;
    q->parr=(int *)calloc(sz,sizeof(int));
    return q;
}

int is_empty(queue *q){
    return (q->front==-1);
}

int is_full(queue *q){
    return ((q->top+1)%q->size==q->front);
}
void enqueue(queue *q,int x){
    if(is_full(q)){
        printf("Queue overflow !!\n");
        return;
    }
   
    if(q->front==-1){ //initial ,if queue is empty
        q->front=0;
        q->top=0;
    }
    else {
        q->top=(q->top+1)%q->size;
        //top moves around ,insert new element
        //front stays fixed
    }
    q->parr[q->top]=x;
}

int dequeue(queue *q){
    if(is_empty(q)){
        printf("Queue is empry\nqueue underflow !!\n");
        return -1;
    }
    int x=q->parr[q->front];
    
    if(q->front==q->top){
        //only one element exsit ,hence after deq. queue will be epmty
        q->front=-1;
        q->top=-1;
        //both front,top are set to -1,indicating queue is emepty
    }
    else {
        q->front=(q->front+1)%q->size;
        //in deleteing(deq.) front moves aroud ,track front lement
        //only front moves,top stays still
    }
    return x;
}

void display(queue *q){
    if(is_empty(q)){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue element are : \n");
    for(int i=q->front;i!=q->top;i=(i+1)%q->size){
        //printf("%d ",*(q->parr+i));
        printf("%d ",q->parr[i]);
    }
    //stops when i==q->tops, missed top element
    printf("%d ",q->parr[q->top]);
    printf("\n");
}
void freeQueue(queue *q){
    free(q->parr);
    free(q);
}

int peek(queue *q){
    //return current front element
    if(is_empty(q)){
        printf("queue is empty !!\n");
        return -1;
    }
    return q->parr[q->front];
}

int main(){
    int n;
    scanf("%d",&n);
    queue *q1=createQueue(n);
    enqueue(q1,10);
    enqueue(q1,20);
    enqueue(q1,30);
    display(q1);
    printf("%d\n",peek(q1));
    dequeue(q1);
    display(q1);
    dequeue(q1);
    display(q1);
    freeQueue(q1);
    return 0;
}