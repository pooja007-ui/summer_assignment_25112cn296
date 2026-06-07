#include<stdio.h>
int main(){
    int bin,dec=0,p=1,r;
    printf("enter binary number");
    scanf("%d",&bin);
    while(bin>0){
        r=bin%10;
        dec=dec+(r*p);
        p=p*2;
        bin=bin/10;
    }
    printf("decimal equivalent=%d",dec);
    return 0;
}