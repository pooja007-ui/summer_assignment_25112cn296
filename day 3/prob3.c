#include<stdio.h>
int main(){
    int a,b,t;
    printf("enter 2 positive integers:");
    scanf("%d%d",&a,&b);
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    printf("GCD of given numbers=%d",a);
    return 0;
}