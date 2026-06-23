 #include<stdio.h>
 #include<string.h>
 int main(){
    char s1[30],s2[30];
    int l1,l2,i,j,f;
    printf("enter 1st string:");
    scanf("%[^\n]",s1);
    getchar();
    printf("\nenter 2nd string:");
    scanf("%[^\n]",s2);
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1!=l2){
        printf("not anagrams");
        return 0;
    }
    for(i=0;i<l1;i++){
        f=0;
        for(j=0;j<l2;j++){
            if(s1[i]==s2[j]){
                s2[j]='0';
                f=1;
                break;
            }
        }
        if(!f){
            printf("not anagrams");
            return 0;
        }
    }
    printf("given strings are anagrams");
    return 0;
 }