#include<stdio.h>
#include<math.h>
int main(){
    int dec,bin=0,r,p=1;
    printf("enter a decimal number:");
    scanf("%d",&dec);
    while(dec>0){
        r=dec%2;
        bin=bin+(p*r);
        p=p*10;
        dec=dec/2;
    }
    printf("binary equivalent=%d",bin);
    return 0;
}