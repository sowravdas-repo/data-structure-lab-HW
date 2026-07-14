#include<stdio.h>
typedef long long ll;

double sqrt_notperfect(double k){
    double low=1,high=k,mid;
    int iteration=100;
    while(iteration--){  //more iteration means more precisions
        mid=(low+high)/2;
        if(mid*mid > k) high=mid;
        else low=mid;
    }
    return mid;
}

ll sqrt_perfect(ll k){
    ll low=1;
    ll high=k;
    ll mid;
    while(high >= low){
        mid=(high+low)/2;
        if(mid*mid==k){
            return mid;
        }
        else if(mid*mid > k){ //element is in the left side
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    ll  k;
    scanf("%lld",&k);
    ll ans=sqrt_perfect(k);
    if(ans!=-1){
        printf("\nSquare root of %lld is %lld ",k,ans);
    }
    else{
      printf("\nThe number is not a perfect square");
    }

    double ans2=sqrt_notperfect(175);
    printf("\n%5lf",ans2);
    return 0;
}