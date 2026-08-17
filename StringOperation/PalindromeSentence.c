//assuming expecting single words
#include<stdio.h>
#include<string.h>

int is_palindrome(char s[]){
    int l=strlen(s);
    if(s[l-1]=='\n'){
        s[l-1]='\0';
        l--;
    }
    int i=0,j=l-1;
    while(i<=j){
        if(s[i]!=s[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);

    (is_palindrome(str)) ? printf("Palindrome\n") : printf("Not a palindrome\n");
    return 0;
}