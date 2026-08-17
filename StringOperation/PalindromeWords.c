//assuming expecting single words
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    scanf("%[^\n]s",str);
    int x=strlen(str);
    int i=0,j=x-1;
    int f=1;
    while(i<=j){
        if(str[i]!=str[j]){
            f=0;
            break;
        }
        i++;
        j--;
    }
    (f) ? printf("Palindrome\n") : printf("Not a palindrome\n");
    return 0;
}