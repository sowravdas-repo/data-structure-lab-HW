#include<stdio.h>
long long factorial(int n){
    if(n <= 1) return 1;
    return n*factorial(n-1);
}
int main(){
    int n;
    scanf("%d",&n);
    
    if(n < 0){
        printf("invalid input !\n");
        printf("There is no Factorial value for negetive number.");
        return 1;

    }

    long long fact=factorial(n);
    printf("%lld\n",fact);
    return 0;
}