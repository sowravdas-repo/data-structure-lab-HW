#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *nextptr;
}node;
node *createnode(int x){
    node *newnode=(node*)malloc(sizeof(node));

    if(newnode==NULL){
        printf("memmory alloc failed!!\n");
        //this failed solely bcz of system,when it run out of memory
        return NULL;
    }
    newnode->value=x;
    newnode->nextptr=NULL;
    return newnode;
}
void insertfront(node **head,int value){
    node *newnode=createnode(value);
    newnode->nextptr=*head;
    *head=newnode;
}
void insertback(node **head,int value){
    node *newnode=createnode(value);
    if(*head==NULL){
        *head=newnode;
        return;
    }

    node *tmp=*head;
    while((*tmp).nextptr!=NULL){
        tmp=(*tmp).nextptr;
        //tmp=tmp->nextptr;
    }
    tmp->nextptr=newnode;
}
void insertposition(node **head,int value,int pos){
    node *newnode=createnode(value);
    
}
void display(node *head){
    node *tmp=head;
    while(tmp!=NULL){
        printf("%d ",(*tmp).value);
        tmp=tmp->nextptr;
    }
    printf("\n");
}
int main(){
    node *head=NULL;
    insertfront(&head,10);
    display(head);
    insertfront(&head,50);
    insertback(&head,40);
    display(head);
    display(head);
    insertfront(&head,100);
    display(head);
    insertback(&head,30);
    display(head);

    return 0;
}