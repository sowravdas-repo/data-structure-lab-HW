/* basic understanding how c allocatte memory dynamically
truned out its just a pointer p ,that just points to a addres and then 
we just store values contigously just like an array
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *p; //p store a addres a ,assume p-->1000 addres
    p=(int *)calloc(sizeof(int),4);
    /* after allocatiiing : 
     p=1000;
     aasuming sizeof(int)=4 byts
     p+0->1000 >p[0]
     p+1->1004 >p[1]
     p+2->1008 >p[2]
     p+3->1012 >p[3]
     henece ,p always poointes to 1000 addres
    */
    for(int i=0;i<4;i++){
        scanf("%d",p+i); //p+1 -- &p[i] equivalent
    }
    printf("\nfisrt element that p pointes -> %d\n",*p);
    for(int i=0;i<4;i++){
        printf("%d ",*(p+i));
    }
    return 0;
}