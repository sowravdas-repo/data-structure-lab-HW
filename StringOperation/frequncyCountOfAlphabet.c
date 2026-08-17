#include<stdio.h>
#include<string.h>
typedef struct{
    char ch;
    int cnt;
}freq;

int main(){
    freq f[26];
    for(int i=0;i<26;i++){
        f[i].ch=97+i;
        f[i].cnt=0;
    }

    char str[150];
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<strlen(str);i++){
        f[str[i]-'a'].cnt++;
    }
    
    //all letters occurence
    for(int i=0;i<26;i++){
        printf("%c -> %d\n",f[i].ch,f[i].cnt);
    }
    printf("\n");

    //only letters thats appers on the sentence
    for(int i=0;i<26;i++){
        if(f[i].cnt!=0){
            printf("%c -> %d\n",f[i].ch,f[i].cnt);
        }
    }
    return 0;
}