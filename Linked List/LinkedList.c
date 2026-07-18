/*
  LINKEDLIST IMPELENTATION

  Unlike Array LList consist of node ,which connected to each other
  one node consist of two things a value and addres of next node
  basic operation on LList : i/ insertion : front,back,any postion(in this program
  1 based indexing) ,ii/deletion : front,back ,iii/searching elemnt
*/

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
    if(pos==1){
        insertfront(head,value);
        return;
    }
    else {
        node *newnode=createnode(value);
        node *tmp=*head;
        for(int i=1;i<pos-1 && tmp!=NULL;i++){
            tmp=tmp->nextptr;
        }

        if(tmp==NULL){
            printf("Invalid positon !!\n");
            free(newnode);
            return;
        }
        newnode->nextptr=tmp->nextptr;
        tmp->nextptr=newnode;

    }

}
void deletefront(node **head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    node *tmp=*head;
    *head=(*head)->nextptr;
    free(tmp);
}

void deleteback(node **head){
    if(*head==NULL){
        printf("List is empty\n");
        return;
    }
    if((*head)->nextptr==NULL){
        free(*head);
        *head=NULL;
        return;
    }
    node *tmp=*head;
    while(tmp->nextptr->nextptr!=NULL) tmp=tmp->nextptr;

    free(tmp->nextptr);
    tmp->nextptr=NULL;
}

void display(node *head){
    node *tmp=head;
    while(tmp!=NULL){
        printf("%d ",(*tmp).value);
        tmp=tmp->nextptr;
    }
    printf("\n");
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

int main(){
    //initialization
    node *head=NULL;

    //insertion
    printf("Insertion elavoratly :\n");
    insertfront(&head,30);
    display(head);
    insertfront(&head,20);
    display(head);
    insertfront(&head,10);
    display(head);

    insertback(&head,40);
    display(head);
    insertback(&head,50);
    display(head);
    
    insertposition(&head,99,3);
    display(head);
    insertposition(&head,100,1);
    display(head);

    //Deletion
    
    printf("\ncurrent LList element : \n");
    display(head);
    printf("elment after each deletion :\n");
    deletefront(&head);
    display(head);
    deletefront(&head);
    display(head);
    deleteback(&head);
    display(head);

    //Searching
    printf("\nSearching : \n");
    int k=30;
    node *ele=search(head,k);
    if(ele != NULL) printf("%d found\n",ele->value);
    else printf("Not Found\n");
    
    

    return 0;
}