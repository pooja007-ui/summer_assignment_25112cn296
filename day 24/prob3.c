#include<stdio.h>
#include<string.h>
int main(){
    char s[100],longw[50];
    int l,maxlen=0,currentlen=0,start=0;
    printf("enter sentence:");
    scanf("%[^\n]",s);
    l=strlen(s);
    for(int i=0;i<=l;i++){
        if(s[i]==' '||s[i]=='\0'){
            if(currentlen>maxlen){
                maxlen=currentlen;
                for(int k=0;k<maxlen;k++){
                    longw[k]=s[start+k];
                }
                longw[maxlen]='\0';
            }
            currentlen=0;
            start=i+1;
        }
        else{
            currentlen++;
        }
    }
    printf("longest word:%s\n",longw);
    printf("length:%d",maxlen);
    return 0;
}