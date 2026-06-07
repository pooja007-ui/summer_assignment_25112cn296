#include<stdio.h>
int reverse(int n,int rev){
    int r;
    if(n==0)
    return rev;
    r=n%10;
    rev=rev*10+r;
    return reverse(n/10,rev);
}
int main(){
    int num,rev=0;
    printf("enter a number:");
    scanf("%d",&num);
    printf("reverse=%d",reverse(num,rev));
    return 0;
}
