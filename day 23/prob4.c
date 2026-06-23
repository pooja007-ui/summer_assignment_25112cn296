#include<stdio.h>
#include<string.h>
int main(){
    char s[60],ch='\0';
    int i,j,l,c,maxc=0;
    printf("enter string:");
    scanf("%[^\n]",s);
    l=strlen(s);
    for(i=0;i<l;i++){
        c=0;
        for(j=0;j<l;j++){
            if(s[i]==s[j])
            c++;
        }
        if(c>maxc){
            maxc=c;
            ch=s[i];
        }
    }
    printf("maximum occurring character:%c,occurs:%d times",ch,maxc);
    return 0;
}