#include<stdio.h>
int main(){
    int a,i,c=0;
    printf("enter a number:");
    scanf("%d",&a);
    for(i=2;i<=a/2;i++){
        if(a%i==0){
            c=c+1;
            break;
        }
    }
    if(a==0||a==1)
    printf("not prime");
    else{
        if(c==0)
        printf("prime");
        else
        printf("not prime");
    }
    return 0;
}
