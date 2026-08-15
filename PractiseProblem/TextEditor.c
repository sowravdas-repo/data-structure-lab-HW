#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    int top;
    int size;
    char **p;
}stack;

stack createstack(int sz){
    stack *s=(char**)malloc(sizeof(stack));
    s->top=-1;
    s->size=sz;
    s->p=(char**)malloc(sizeof(char*)*sz);
    return s;
}

int is_empty(stack *s){
    return s->top==-1;
}

int is_full(stack *s){
    return s->top==s->size-1;
}

void push(stack *s,char *t){
      if(is_full(s)){
        printf("Stack is full\n");
        return;
      }
      s->top=(char*)malloc(strlen(t)+1);
      strcpy(s->p[s->top],t);
}

char pop(stack *s){
    if(is_empty(s)){
        printf("stack is empty\n");
        return ;
    }

    char *temp=s->p[s->top];
    s->top--;
    return temp;
}
int main(){
     stack *undo=createstack(50);
     stack *redo=createstack(50);
    char str[50];
     char choice;
     while(99){
        switch(choice){
            case 'w' :
               scanf("[^\n]%s",s);
               push(redo,str);
               break;
            case 'z' :
               push()
               
        }
     }
       
    return 0;
}