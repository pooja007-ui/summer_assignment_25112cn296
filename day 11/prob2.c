#include<stdio.h>
int max(int num1,int num2){
    if(num1>num2)
    return num1;
    else
    return num2;
}
int main(){
    int a,b;
    printf("enter 2 numbers:");
    scanf("%d%d",&a,&b);
    printf("maximum number:%d",max(a,b));
    return 0;
}