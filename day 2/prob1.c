#include<stdio.h>
int main(){
    int a,r,s=0;
    printf("enter a number:");
    scanf("%d",&a);
    while(a!=0){
        r=a%10;
        s=s+r;
        a=a/10;
    }
    printf("sum of digits=%d",s);
    return 0;
}