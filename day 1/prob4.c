#include<stdio.h>
int main(){
    int i,a,c=0;
    printf("enter a number:");
    scanf("%d",&a);
    while(a!=0){
        c=c+1;
        a=a/10;
    }
    printf("no. of digits=%d",c);
    return 0;
}