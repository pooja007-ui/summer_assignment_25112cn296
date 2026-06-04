#include<stdio.h>
int main(){
    int a,r,rev=0,a1;
    printf("enter a number:");
    scanf("%d",&a);
    a1=a;
    while(a!=0){
        r=a%10;
        rev=rev*10+r;
        a=a/10;
    }
    if(rev==a1)
    printf("number is palindrome");
    else
    printf("number is not palindrome");
    return 0;
}