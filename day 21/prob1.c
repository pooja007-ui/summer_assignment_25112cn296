#include<stdio.h>
int main(){
    char s[20];
    int len=0;
    printf("enter a string:");
    scanf("%[^\n]",s);
    while(s[len]!='\0'){
        len++;
    }
    printf("length of string:%d",len);
    return 0;
}