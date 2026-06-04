#include<stdio.h>
int main(){
    int a,r,p=1;
    printf("enter a number:");
    scanf("%d",&a);
    while(a!=0){
        r=a%10;
        p=p*r;
        a=a/10;
    }
    printf("product of didgitd=%d",p);
    return 0;
}