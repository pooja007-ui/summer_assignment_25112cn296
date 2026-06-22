#include<stdio.h>
int main(){
    char s[100],ch;
    int c=0,i=0;
    printf("enter a string:");
    scanf("%[^\n]",s);
    printf("\nenter the character to check frequency of:");
    scanf(" %c",&ch);
    while(s[i]!='\0'){
        if(s[i]==ch){
            c++;
        }
        i++;
    }
    printf("ch %c occurs %d times",ch,c);
    return 0;
}