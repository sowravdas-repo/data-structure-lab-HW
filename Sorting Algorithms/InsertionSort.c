#include<stdio.h>
void sort(int a[],int l,int n){
    for(int i=1;i<n;i++){
        int k=a[i];
        int j=i-1;
        for(;j>=0;j--){
            if(a[j] <= k) break;
            a[j+1]=a[j];
        }
        a[j+1]=k;
    }
}
int main(){
    // int a[]={5,2,4,6,1};
    // int n=sizeof(a)/sizeof(a[0]);
    int n; scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",a+i);

    sort(a,0,n);
    
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}