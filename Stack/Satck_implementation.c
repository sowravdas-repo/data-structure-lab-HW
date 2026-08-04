/* demonstartion of how satck data structure works 
sad we cann't show this in cpp style
 like vec_name.pusb(10) instead vec(pointer,value)
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int top;
    int size;
    int *parr;
}stack;

stack *createstack(int sz){ //function should be a pointer since its will return a addres
    stack *STACK=(stack*)malloc(sizeof(stack)); //STACK pointer of stack type
    (*STACK).top=-1;
    (*STACK).size=sz;
    (*STACK).parr=(int*)malloc(sizeof(int)*sz); //initialize dynamic memeory in parr pointer
    return STACK;
}

int is_full(stack *s){
    //return 1 if stack is full, 0 otherwise
    return ((*s).top==(*s).size-1);
}

int is_empty(stack *s){
    //return 1 if there is no element is the stack, 0 if there atlest one exist
    if(s==NULL){
        return 1;
    }
    return ((*s).top==-1);
}

void push(stack *s,int x){ //add element at the end
    if(is_full(s)){
        printf("Stack is full\n");
        return;
    }
    (*s).top++;
    s->parr[(*s).top]=x;
}

int pop(stack *s){
    if(is_empty(s)){
        printf("Stack underflow!!\n");
        return -1;
    }
    int val=s->parr[s->top];
    s->top--;
    return val;
}
int peek(stack *s){ //return the last element
    if(is_empty(s)){
        printf("stack is empty \n ");
        return -1; //means theres no value in stack
    }
    return s->parr[s->top];
}
void freestack(stack *s){
    free(s->parr); //first have to free array containing all element
    free(s); //then free stack
}
int main(){
    int n;
    printf("enter size : ");
    scanf("%d",&n);
    stack *s1=createstack(n); //since after creating the local variable disepper and return an refernece ,hence we need a pointer to store it

    int mm=is_empty(s1);
    printf("%d \n",mm);

    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        push(s1,x);
    }

    for(int i=0;i<=s1->top;i++){
        printf("%d ",s1->parr[i]);
    }
    printf("\nlast element is : %d\n",peek(s1));
    pop(s1);
    printf("now last element is : %d\n",peek(s1));
    freestack(s1);
    s1=NULL;
    int mm1=is_empty(s1);
    printf("%d \n",mm1);
    
    return 0;
}