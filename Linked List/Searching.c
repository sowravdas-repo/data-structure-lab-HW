#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *nextptr;
}node;
node *createnode(int x){
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("alloc falied\n");
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

node *search(node *head,int k){
    node *tmp=head;
    while(tmp!=NULL){
        if(tmp->value==k){
            return tmp;
        }
        tmp=tmp->nextptr;
    }
    return NULL;
}
void display(node *head){
    node *tmp=head;
    if(tmp==NULL){
        printf("list is emplty");
        return;
    }
    while(tmp!=NULL){
        printf("%d ",tmp->value);
        tmp=tmp->nextptr;
    }
    printf("\n");
}
int main(){
     node *head=NULL;
    insertfront(&head,30);
    insertfront(&head,20);
    insertfront(&head,10);
    insertback(&head,40);
    insertback(&head,50);
    insertback(&head,60);
    display(head);

    //seraching
    node *ele=search(head,10);
    if(ele!=NULL) printf("%d Found\n",ele->value);
    else printf("not present\n");
    
    return 0;
}