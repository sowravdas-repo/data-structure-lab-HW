#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}node;
node *createnode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("Memory Allocation failed\n");
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
    if(pos < 0){
        printf("Invalid position\n");
        return;
    }
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
        printf("LList is Empty\n");
        return;
    }
    node *temp=*head;
    *head=temp->next;
    free(temp);
}
void deleteback(node **head){
    if(*head==NULL){
        printf("LList is empty\n");
        return;
    }
    node *temp=*head;
    node *prev=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL) *head=NULL;
    else prev->next=NULL;
    free(temp);
}
void deletebyvalue(node **head,int val){
    if(*head==NULL){
        printf("LList is empty\n");
        return;
    }
    node *prev=NULL;
    node *target=*head;
    if(target->value==val){
        if(target->next==NULL) *head=NULL;
        else{
            *head=target->next;
        }
        free(target);
        return;
    }
    while(target!=NULL){
        if(target->value==val){
            prev->next=target->next;
            free(target);
            return;
        }
        prev=target;
        target=target->next;
    }
    printf("Value Not Found\n");
}
node *search(node **head,int val){
    if(*head==NULL){
        printf("LList is empty\n");
        return NULL;
    }
    node *temp=*head;
    while(temp!=NULL){
        if(temp->value==val){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
int cntnode(node *head){
      node *temp=head;
      int cnt=0;
      while(temp!=NULL){
        cnt++;
        temp=temp->next;
      }
      return cnt;
}
void reverse(node **head){
    if(*head==NULL){
        printf("LList is empty\n");
        return;
    }
    node *curr=*head,*prev=NULL,*next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void freeEntireList(node **head){
    node *temp;
    while(temp!=NULL){
        temp=*head;
        *head=temp->next;
        free(temp);
    }
}
void display(node *head);

int main(){
    node *head=NULL;
    int n; scanf("%d",&n);
    for(int i=0;i<n;i++){
       int x; scanf("%d",&x);
       insertfront(&head,x);
    }
    printf("After insertion at the front : \n");
    display(head);
    printf("\nAfter insertion in the end : \n");
    insertback(&head,99);
    display(head);
    insertback(&head,100);
    display(head);
    
    insertpos(&head,1000,3);
    printf("inserting 1000 at position 3 :\n");
    display(head);

    //deletion
    printf("After Deleting one from front :\n");
    deletefront(&head);
    display(head);
    deleteback(&head);
    printf("After Deleting one from back :\n");
    display(head);
    deletebyvalue(&head,20);
    printf("After Deleting 20 from LList :\n");
    display(head);

    //Searching
    node *res=search(&head,30);
    (res==NULL) ? printf("Not Found\n") : printf("\nValue %d Found\n",res->value);

    //node count
    printf("current node count : %d\n",cntnode(head));
    //Reversing a LList
    printf("\ncurrent List :\n");
    display(head);
    reverse(&head);
    printf("after reversed : \n");
    display(head);
    
    //free enitire Llist
    freeEntireList(&head);
    display(head);
    return 0;
}

void display(node *head){
    if(head==NULL){
        printf("LList is empty\n");
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}