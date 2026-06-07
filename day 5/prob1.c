#include<stdio.h>
int main(){
    int i,a,s=0;
    printf("enter a positive  integer");
    scanf("%d",&a);
    for(i=1;i<a;i++){
        if(a%i==0)
        s=s+i;
    }
    if(s==a)
    printf("perfect number");
    else
    printf("not a perfect number");
    return 0;
}