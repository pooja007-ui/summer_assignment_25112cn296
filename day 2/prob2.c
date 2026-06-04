#include<stdio.h>
int main(){
    int a,r,rev=0;
    printf("enter a number:");
    scanf("%d",&a);
    while(a!=0){
        r=a%10;
        rev=rev*10+r;
        a=a/10;
    }
    printf("reverse=%d",rev);
    return 0;
}