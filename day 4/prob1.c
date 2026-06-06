#include<stdio.h>
int main(){
    int n,i,a=0,b=1,c;
    printf("enter the no. of terms:");
    scanf("%d",&n);
    printf("fibonacci series:");
    printf("%d\t",a);
    printf("%d\t",b);
    for(i=1;i<=n-2;i++){
        c=a+b;
        a=b;
        b=c;
        printf("%d\t",c);
    }
    return 0;
}