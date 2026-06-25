#include<stdio.h>
#include<string.h>
int main(){
    char s1[20],s2[20];
    int l1,l2,i,j;
    printf("enter 1st string:");
    scanf("%[^\n]",s1);
    getchar();
    printf("\nenter 2nd string:");
    scanf("%[^\n]",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    printf("common characters:");
    for(i=0;i<l1;i++){
        for(j=0;j<l2;j++){
            if(s1[i]==s2[j]){
                printf("%c\t",s1[i]);
                s2[j]='*';
                break;
            }
        }
    }
    return 0;
}