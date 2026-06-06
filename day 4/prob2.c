#include<stdio.h>
int fib(int n){
    if(n==0||n==1)
    return n;
    else{
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return b;
    }
}
int main(){
    int n,r;
    printf("enter positive integer n:");
    scanf("%d",&n);
    r=fib(n);
    printf("%dth fibonacci term=%d",n,r);
    return 0;
}