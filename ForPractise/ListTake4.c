#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int value;
    struct node *next;
}node;
node *createnode(int val){
    node *newnode=(node*)malloc(sizeof(node));
    if(newnode==NULL){
        printf("memory allocation Failed\n");
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
        printf("list is empty\n");
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
    if(prev==NULL) *head=NULL;
    else prev->next=NULL;
    free(temp);
}
void deletebyvalue(node **head,int val){
    if(*head==NULL){
        printf("llist is empty\n");
        return;
    }
    node *prev=NULL;
    node *target=*head;
    if(target->value==val){
        if(target->next==NULL) *head=NULL;
        else *head=target->next;
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
    printf("value not found\n");
}
node *search(node *head,int val){
    if(head==NULL){
        printf("list is empty\n");
        return NULL;
    }
    node *temp=head;
    while(temp!=NULL){
        if(temp->value==val){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
int cntnode(node *head){
    if(head==NULL){
        printf("List is empty\n");
        return 0;
    }
    node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
void reverse(node **head){
    node *prev=NULL;
    node *curr=*head;
    node *next;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    *head=prev;
}
void freeEntire(node **head){
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
 deleteback(&head);
 int n; scanf("%d",&n);
 for(int i=0;i<n;i++){
    int x; scanf("%d",&x);
    insertfront(&head,x);
 }
 display(head);
 insertback(&head,100);
 display(head);
 deleteback(&head);
 display(head);
 deleteback(&head);
 display(head);
 deletefront(&head);
 display(head);
insertback(&head,20);
display(head);
 deletebyvalue(&head,20);
 display(head);
 node *sn=search(head,30);
 (sn==NULL) ? printf("Not found\n") : printf("\n%d found\n",sn->value);
 printf("%d\n",cntnode(head));
 reverse(&head);
 display(head);
 freeEntire(&head);
 display(head)
;    return 0;
}
void display(node *head){
    if(head==NULL){
        printf("list is empty\n");
        return;
    }
    node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->value);
        temp=temp->next;
    }
    printf("\n");
}