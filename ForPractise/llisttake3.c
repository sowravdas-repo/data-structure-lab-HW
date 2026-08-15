#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}node;
node *createnode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("memory allocation failed\n");
        return NULL;
    }
    newnode->value=val;
    newnode->next=NULL;
    return newnode;
}
void insertfront(node **head,int val){
    node *newnode=createnode(val);
    newnode->next=*head;
    *head=newnode;
}
void insertback(node **head,int val){
    node *newnode=createnode(val);
    if(*head==NULL){
        *head=newnode;
        return;
    }
    node *temp=*head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
}
void insertpos(node **head,int val,int pos){
    if(pos==1){
        insertfront(head,val);
        return;
    }
    node *newnode=createnode(val);
    node *temp=*head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
  
}
void deletefront(node **head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    node *temp=*head;
    *head=temp->next;
    free(temp);
}
void deleteback(node **head){
    if(*head==NULL){
        printf("list is empty\n");
        return;
    }
    node *temp=*head;
    node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL){
        *head=NULL;
    }
    else{
       prev->next=NULL;
    }
    free(temp);
}
void display(node *head){
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}
int main(){
  node *head=NULL;
  insertfront(&head,10);
  printf("%d \n",head->value);
  insertback(&head,100);
  display(head);
  insertpos(&head,99,2);
  display(head);
  deletefront(&head);
  display(head);
  deleteback(&head);
  display(head);
    return 0;
}