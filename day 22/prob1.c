#include<stdio.h>
#include<string.h>
int main(){
    char s[50];
    int r,l=0,ispalin=1;
    printf("enter a string:");
    scanf("%[^\n]",s);
    r=strlen(s)-1;
    while(l<r){
        if(s[l]!=s[r]){
            ispalin=0;
            break;
        }
        l++;
        r--;
    }
    if(ispalin)
    printf("palindrome string");
    else
    printf("not palindrome");
    return 0;
}