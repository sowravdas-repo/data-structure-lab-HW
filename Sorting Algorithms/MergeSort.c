#include<stdio.h>
void merge(int *arr,int l,int mid,int r);
void mergesort(int *arr,int l,int r){
    //base case
    if(l>=r) return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void merge(int *arr,int l,int mid,int r){
    int a1=mid-l+1,b1=r-mid;
    int A[a1],B[b1];
    for(int i=0;i<a1;i++) A[i]=arr[l+i];
    for(int i=0;i<b1;i++) B[i]=arr[mid+1+i];

    int i=0,j=0,k=l;
    while(i<a1 && j<b1){
        if(A[i] < B[j]){
            arr[k]=A[i];
            i++;
        }
        else{
            arr[k]=B[j];
            j++;
        }
        k++;
    }

    while(i<a1) arr[k++]=A[i++];
    while(j<b1) arr[k++]=B[j++];
}
int main(){
    int arr[]={4,3,5,2,33,11,44,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int begin=0,end=n-1;
    mergesort(arr,begin,end);

    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}