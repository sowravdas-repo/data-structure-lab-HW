#include<stdio.h>
int main(){
    int a[]={2,3,11,25,26,27,35,45,50,50,60,66,89,100,150};
    int n=15; //size of the array
    int k;
    printf("Which elemnt to search : ");
    scanf("%d",&k);
    int idx=-1;
    for(int i=0;i<n;i++){
        if(a[i]==k){
            idx=i;
            break;
        }
    }
    (idx!=-1) ? printf("\nFound at index %d ",idx) : printf("\nnot found");
    //As it check on every element once overall time com. O(n);
    return 0;
}