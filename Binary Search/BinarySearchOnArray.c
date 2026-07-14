/*
Binary Search
IN B-search array must sorted.
we first comopare with mid element and if the element is found the search end,
and if the array[mid] is not the desired element ,then it must be either smaller
or bigger .And as the array sorted if a[mid] is smaller the elemetnt must be in
the left side from the mid, and right side otherwise,we reapet this untill we
find the elemnt.
As in every pass it shrink the array search range the complexity reduced to 
O(logN) ,from a linear search which is O(n); 

*/
#include<stdio.h>
int main(){
    int a[]={2,3,11,25,26,27,35,45,50,50,60,66,89,100,150};
    int n=15; //size of the array
    int k;
    printf("Which elemnt to search : ");
    scanf("%d",&k);
    int low=0,high=n-1,mid;
    while(high >= low){
        mid=(high+low)/2;
        if(a[mid]==k){
            printf("\nElemnt found at index %d ",mid);
            return 0;
        }
        else if(a[mid] > k){ //element is in the left side
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    printf("\nelemtn not found");
    return 0;
}