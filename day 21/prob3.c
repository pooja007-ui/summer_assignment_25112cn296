#include<stdio.h>
int main(){
    char s[50];
    int v=0,c=0,i=0;
    printf("enter a string:");
    scanf("%[^\n]",s);
    while(s[i]!='\0'){
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
            v++;
            else
            c++;
        }
        i++;
    }
    printf("no. of vowels:%d\n",v);
    printf("no. of consonants:%d",c);
    return 0;
}