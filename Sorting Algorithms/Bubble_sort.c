#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    //sorting
    for(int i=0;i<n-1;i++){
        int check=1;
        for(int j=0;j<n-1-i;j++){
            if(a[j] > a[j+1]){
                swap(&a[j],&a[j+1]);
                check=0;
            }
        }
        if(check) break;
    }

    //sorted list
    for(int i=0;i<n;i++) printf("%d ",a[i]);
    printf("\n");

    return 0;
}