#include<stdio.h>
int sum(int num1,int num2){
    int s= num1+num2;
    return s;
}
int main(){
    int a,b;
    printf("enter 2 numbers:");
    scanf("%d%d",&a,&b);
    printf("sum=%d",sum(a,b));
    return 0;
}