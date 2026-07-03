#include<stdio.h>
#include<stdlib.h>
int *createDA(int size){
    return (calloc(size,sizeof(int)));
}
int *resize(int *p,int n){
    if(p==NULL){
        printf("\narray is empty\nREalloc failed !!\n");
        return p; //keeping the old pointer
    }
    int *temp=realloc(p,n*sizeof(int));
    if(temp==NULL){
        printf("Reallocation failed");
        return p;
    }
    return temp;
}
void display(int *p,int first,int last){
    for(int i=first;i<last;i++){
        //printf("%d ",*(p+i));
        printf("%d ",p[i]);
    }
}
int main(){
    int *p;
    int n;
    printf("enter size : ");
    scanf("%d",&n);
    p=createDA(n); //as calloc,malloc,realloc all return a pointer
    printf("enter %d intergers :\n");
    for(int i=0;i<n;i++){
        //scanf("%d",&p[i]);
        scanf("%d",p+i);
    }
    printf("\n%d element are :\n",n);
    display(p,0,n );
    printf("\n");

    //resizing array
    int m;
    printf("enetr no. of new ele : ");
    scanf("%d",&m);
    int new_size=n+m; //it will keep all prevous element with newer once
    p=resize(p,(new_size));
    printf("\nenter %d new  element :\n",m);
    for(int i=n;i<new_size;i++){
        scanf("%d",p+i);
        //scanf("%d",&p[i]);
    }
    printf("\nnewly added element : \n");
    display(p,n,new_size);
    printf("\nall element are : \n");
    display(p,0,new_size);
    free(p);
    p=NULL; //now p pointes null
    return 0;
}