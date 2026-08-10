#include<stdio.h>

void setAllzero(int freq[],int a,int b){
   for(int i=a;i<b;i++) freq[i]=0;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int k=-1; //initial valur for max element
    for(int i=0;i<n;i++){
         scanf("%d",&a[i]);
         if(k < a[i]) k=a[i];
    }

    int freq[k+1];
    setAllzero(freq,0,k+1);

   for(int i=0;i<n;i++) freq[a[i]]++;

    //for(int i=0;i<k+1;i++) printf("%d ",freq[i]);
    for(int i=0;i<=k;i++){
        while(freq[i] > 0){
            // printf("%d ",freq[a[i]]);
            printf("%d ",i);
            freq[i]--;
        }
    }
    printf("\n");
    return 0;
}