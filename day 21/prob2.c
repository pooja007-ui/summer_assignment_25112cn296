#include<stdio.h>
#include<string.h>
int main(){
    char s[100],t;
    int i,len;
    printf("enter a string:");
    scanf("%[^\n]",s);
    len=strlen(s);
    for(i=0;i<len/2;i++){
        t=s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=t;
    }
    printf("reversed string:%s",s);
    return 0;
}