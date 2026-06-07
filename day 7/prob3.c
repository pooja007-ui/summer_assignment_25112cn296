#include<stdio.h>
int sd(int n){
    if(n==0)
    return n;
    else
    return (n%10)+ sd(n/10);
}
int main(){
    int num;
    printf("enter a number:");
    scanf("%d",&num);
    printf("sum of digits=%d",sd(num));
    return 0;
}