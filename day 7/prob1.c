#include<stdio.h>
unsigned long int factorial(int n){
    if(n==0||n==1)
    return 1;
    else
    return n*factorial(n-1);
}
int main(){
    int num;
    printf("enter a positive integer:");
    scanf("%d",&num);
    printf("factorial of %d=%lu",num,factorial(num));
    return 0;
}