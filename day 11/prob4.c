#include<stdio.h>
int fact(int num){
    int f=1;
    if(num==0||num==1)
    return 1;
    for(int i=num;i>=1;i--){
        f=f*i;
    }
    return f;
}
int main(){
    int a;
    printf("enter a number:");
    scanf("%d",&a);
    printf("factorial of %d=%d",a,fact(a));
    return 0;
}