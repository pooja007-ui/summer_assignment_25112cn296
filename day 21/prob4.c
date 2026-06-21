#include<stdio.h>
int main(){
    char s[50];
    int i=0;
    printf("enter string:");
    scanf("%[^\n]",s);
    while(s[i]!='\0'){
        if(s[i]>='a'&&s[i]<='z')
        s[i]=s[i]-32;
        i++;
    }
    printf("uppercase string:%s",s);
    return 0;
}