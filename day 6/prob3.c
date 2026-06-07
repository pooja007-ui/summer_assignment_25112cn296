#include<stdio.h>
int main(){
    unsigned int n;
    int c=0;
    printf("enter decimal number:");
    scanf("%u",&n);
    while(n>0){
        n=n&(n-1);
        c++;
    }
    printf("no. of set bits in given number=%d",c);
    return 0;
}