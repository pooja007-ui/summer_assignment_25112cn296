#include<stdio.h>
int main(){
    int a,a1,r,s=0,i;
    long f;
    printf("enter a positive integer");
    scanf("%d",&a);
    a1=a;
    while(a>0){
        r=a%10;
        f=1;
        for(i=1;i<=r;i++){
            f=f*i;
        }
        s=s+f;
        a=a/10;
    }
    if(s==a1)
    printf("strong number");
    else
    printf("not a strong number");
    return 0;
}