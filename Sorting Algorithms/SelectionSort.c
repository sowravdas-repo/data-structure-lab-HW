#include<stdio.h>
#include<math.h>
#include<limits.h>
void swap(int *a,int *b){
   int temp=*a;
   *a=*b;
   *b=temp;
}
int main(){
    int a[8]={4,3,5,2,1,6,10,99};
    int n=sizeof(a)/sizeof(a[0]);

    //selection sort
    for(int i=0;i<n;i++){
         int mn=INT_MAX;
         int idx=-1;
        for(int j=i;j<n;j++){
             if(mn > a[j]){
                 mn=a[j];
                 idx=j;
             }
        }
        swap(&a[i],&a[idx]);
    }

    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");
    return 0;
}