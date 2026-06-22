#include<stdio.h>
int main(){
    char s[100];
    int i=0,c=0,inword=0;
    printf("enter a string:");
    scanf("%[^\n]",s);
    while(s[i]!='\0'){
        if(s[i]!=' '){
            if(inword==0){
                inword=1;
                c++;
            }
        }
        else
        inword=0;
        i++;
    }
    printf("no. of words in given sentence:%d",c);
    return 0;
}