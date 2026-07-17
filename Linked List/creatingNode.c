#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *nextptr;
}node;

node *createnode(int x){
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("memory alloc. failed\n");
        return NULL;
    }
    newnode->value=x;
    (*newnode).nextptr=NULL;
    return newnode;
}
int main(){
   node *head=NULL;
   head=createnode(10);
   printf("%d\n",head->value);
    head=createnode(100);
   printf("%d\n",head->value);
    free(head);
    return 0;
}