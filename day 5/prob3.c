#include<stdio.h>
int main(){
    int i,a;
    printf("enter a number:");
    scanf("%d",&a);
    printf("factors=");
    for(i=1;i<=a;i++){
        if(a%i==0)
        printf("%d\t",i);

    }
    return 0;
}