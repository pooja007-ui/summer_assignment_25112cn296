#include<stdio.h>
#include<string.h>
int main(){
    char s1[50],s2[50];
    int l1,l2,isrot=0;
    printf("enter 1st string:");
    scanf("%[^\n]",s1);
    getchar();
    printf("\nenter 2nd string:");
    scanf("%[^\n]",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1==l2){
        char t[2*l1+1];
        strcpy(t,s1);
        strcat(t,s1);
        if(strstr(t,s2)!=NULL){
            isrot=1;
        }
    }
    if(isrot){
        printf("%s is a rotation of %s",s2,s1);
    }
    else{
        printf("%s not a rotation of %s",s2,s1);
    }
    return 0;
}