#include<stdio.h>
int main(){
    int i,a,b,c;
    printf("enter number and exponent:");
    scanf("%d%d",&a,&b);
    int t=a;
    for(i=1;i<=b;i++){
        a=a*b;
    }
    printf("%d^%d=%d",t,b,a);
    return 0;
}