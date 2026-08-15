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
    else{
        node *newnode=createnode(val);
        node *temp=*head;
        for(int i=1;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void display(node *head){
    if(head==NULL){
        printf("List is empty\n\n");
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
 int n;
 scanf("%d",&n);
 for(int i=0;i<n;i++){
    int x;
    scanf("%d",&x);
    insertfront(&head,x);
    display(head);
 }
 display(head);
 insertback(&head,99);
 display(head);
 insertpos(&head,80,3);
 display(head);
    return 0;
}