#include<stdio.h>
int main(){
    char s[100];
    int c=0,i=0;
    printf("enter string:");
    scanf("%[^\n]",s);
    while(s[i]!='\0'){
        if(s[i]!=' '){
            s[c++]=s[i];
        }
        i++;
    }
    s[c]='\0';
    printf("string after removed spaces:%s",s);
    return 0;
}