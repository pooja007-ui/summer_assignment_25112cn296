#include<stdio.h>
int fib(int n){
    if(n==0||n==1)
    return n;
    else
    return fib(n-1)+fib(n-2);
}
int main(){
    int t;
    printf("enter no. of terms:");
    scanf("%d",&t);
    printf("fibonacci series:");
    for(int i=0;i<t;i++)
    printf("%d\t",fib(i));
    return 0;
}