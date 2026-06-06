#include<stdio.h>
int main(){
    int a,b,t,gcd,a1,b1;
    printf("enter 2 positive integers:");
    scanf("%d%d",&a,&b);
    a1=a;
    b1=b;
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    gcd=a;
    printf("LCM of given 2 numbers =%d",a1*b1/gcd);
    return 0;
}