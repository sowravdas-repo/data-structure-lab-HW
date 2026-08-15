#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int top;
    int size;
    int *p;
}stack;

stack *createstack(int sz){
    stack *s=(stack*)malloc(sizeof(stack));
    s->top=-1;
    s->size=sz;
    s->p=(int*)malloc(sizeof(int)*sz);
    return s;
}

int is_empty(stack *s){
    if(s==NULL) return 1;
    return s->top==-1;
}
int is_full(stack *s){
    return s->top==s->size-1;
}

void push_back(stack *s,int val){
    if(is_full(s)){
        printf("stack is full !!\n");
        return;
    }
    s->top++;
    s->p[s->top]=val;
}

int pop_back(stack *s){
    if(is_empty(s)){
        printf("stack is empty \n");
        return -1;
    }
    int temp=s->p[s->top];
    s->top--;
    return temp;
}
void display(stack *s){
    if(is_empty(s)){
        printf("Satck is empty \n");
        return;
    }
    for(int i=0;i<=s->top;i++) printf("%d ",s->p[i]);
    printf("\n");
}
int main(){
    stack *s1=createstack(5);
    push_back(s1,100);
    printf("%d \n",s1->p[s1->top]);
    int n;
    scanf("%d ",&n);
    stack *s2=createstack(n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push_back(s2,x);
    }
    display(s2);
    return 0;
}