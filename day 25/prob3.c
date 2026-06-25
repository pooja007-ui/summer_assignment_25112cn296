#include<stdio.h>
#include<string.h>
int main(){
    char temp[50];
    int n,i,j;
    printf("enter the no. of names:");
    scanf("%d",&n);
    char names[n][50];
    printf("enter names:\n");
    for(i=0;i<n;i++){
        scanf(" %[^\n]",names[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(strcmp(names[j],names[j+1])>0){
                strcpy(temp,names[j]);
                strcpy(names[j],names[j+1]);
                strcpy(names[j+1],temp);
            }
        }
    }
    printf("names alphabetically sorted:\n");
    for(i=0;i<n;i++){
        printf("%s\n",names[i]);
    }
    return 0;
}