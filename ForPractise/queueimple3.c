#include<stdio.h>
#include<stdlib.h>
typedef struct{
    int front;
    int top;
    int size;
    char *p;
}queue;
queue *createqueue(int n){
    queue *q=(queue*)malloc(sizeof(queue));
    q->front=-1;
    q->top=-1;
    q->size=n;
    q->p=(char*)malloc(sizeof(char)*n);
    return q;
}
int is_empty(queue *q){
    return q->front==-1;
}
int is_full(queue *q){
    return (q->top+1)%q->size==q->front;
}
void enqueue(queue *q,char val){
    if(is_full(q)){
        printf("Queue overfloaw\n");
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->top=0;
    }
    else {
        q->top=(q->top+1)%q->size;
    }
    q->p[q->top]=val;
}
char dequeue(queue *q){
    if(is_empty(q)){
        printf("Queue underflow\n");
        return '\0';
    }
    char temp=q->p[q->front];
    if(q->front==q->top){
        q->front=-1;
        q->top=-1;
    }
    else {
        q->front=(q->front+1)%q->size;
    }
    return temp;
}

void display(queue *q){
    if(is_empty(q)){
        printf("Qurnr is empty\n");
        return;
    }
    for(int i=q->front;i!=q->top;i=(i+1)%q->size){
        printf("%c",q->p[i]);
    }
    printf("%c",q->p[q->top]);
}
int main(){
    int n;
    scanf("%d",&n);
    queue *q1=createqueue(n);
    for(int i=0;i<n;i++){
        char c;
        scanf(" %c",&c);
        enqueue(q1,c);
    }
    display(q1);
    return 0;
}