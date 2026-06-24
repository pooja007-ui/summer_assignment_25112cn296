#include<stdio.h>
#include<string.h>
int main(){
    char s[100], rem[100];
    int l,remind=0;
    printf("enter string:");
    scanf("%[^\n]",s);
    l=strlen(s);
    for(int i=0;i<l;i++){
        rem[remind++]=s[i];
        while(i+1<l&&s[i]==s[i+1]){
            i++;
        }
    }
    rem[remind]='\0';
    printf("original string:%s\n",s);
    printf("string without duplicated characters:%s",rem);
    return 0;
}