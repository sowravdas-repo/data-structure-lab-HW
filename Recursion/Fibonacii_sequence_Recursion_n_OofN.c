#include<stdio.h>
void fibo(int n,int a,int b){
    if(n==0) return;
    printf("%d ",a);
    fibo(n-1,b,a+b);
}
int main(){
    int n;
    scanf("%d",&n);
    int first=0,second=1;
    fibo(n,first,second);
    return 0;
}