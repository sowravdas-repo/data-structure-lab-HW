#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}node;
node *createnode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->value=val;
    newnode->next=NULL;
    return newnode;
}
void insertfront(node **head,int val){
    node *newnode=createnode(val);
    newnode->next=*head;
    *head=newnode;
}
void insertend(node **head,int val){
    node *newnode=createnode(val);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    node *tmp=*head;
    while(tmp->next!=NULL){
        tmp=tmp->next;
    }
    tmp->next=newnode;
}
void display(node*head){
   node *temp=head;
 while(temp!=NULL){
    printf("%d ",temp->value);
    temp=temp->next;
 }
}
int main(){
    node *head=NULL;
    insertfront(&head,10);
    display(head);
    return 0;
}