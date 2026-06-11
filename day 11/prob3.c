#include<stdio.h>
int prime(int num1){
    if(num1<=1)
    return 0;
    for(int i=2;i<=num1/2;i++){
        if(num1%i==0)
        return 0;
    }
    return 1;
    }
int main(){
    int a;
    printf("enter number:");
    scanf("%d",&a);
    if(prime(a))
    printf("prime");
    else
    printf("not prime");
    return 0;
}