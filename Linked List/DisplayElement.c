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
void display(node *head){
    node *tmp=head; //we will move tmp, while addrees of head keeps safe
    while(tmp!=NULL){
        printf("%d ",(*tmp).value);
        tmp=tmp->nextptr;
    }
    printf("\n");
}
int main(){
   node *head=NULL;
   head=createnode(10);
   display(head);
   head=createnode(20);
   display(head);
   head=createnode(30);
   display(head);
    free(head);
    return 0;
}