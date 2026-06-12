#include<stdio.h>
void perfectnum(int num){
    int i,s=0;
    for(i=1;i<=num/2;i++){
        if(num%i==0)
        s=s+i;
    }
    if(s==num)
    printf("perfect number");
    else
    printf("not perfect number");
}
int main(){
    int a;
    printf("enter a number:");
    scanf("%d",&a);
    perfectnum(a);
    return 0;
}
