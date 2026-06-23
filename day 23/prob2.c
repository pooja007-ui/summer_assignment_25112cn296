#include<stdio.h>
 #include<string.h>
 int main(){
    char s[50];
    int n,f=0,unique;
    printf("enter string:");
    scanf("%[^\n]",s);
    n=strlen(s);
    for(int i=0;i<n;i++){
        unique=1;
        for(int j=0;j<n;j++){
            if(i!=j&&s[i]==s[j]){
                unique=0;
                break;
            }
        }
        if(!unique){
            printf("first repeating character:%c",s[i]);
            f=1;
            break;
        }
    }
    if(!f)
    printf("no repeating character found");
    return 0;
 }