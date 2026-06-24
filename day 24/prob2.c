#include<stdio.h>
#include<string.h>
int main(){
    char s[100], comp[100];
    int l,compind=0;
    printf("enter string:");
    scanf("%[^\n]",s);
    l=strlen(s);
    for(int i=0;i<l;i++){
        int c=1;
        while(i+1<l&&s[i]==s[i+1]){
            c++;
            i++;
        }
        comp[compind++]=s[i];
        if(c>1){
            comp[compind++]=c+'0';
        }
    }
    comp[compind]='\0';
    printf("compressed string:%s",comp);
    return 0;
}