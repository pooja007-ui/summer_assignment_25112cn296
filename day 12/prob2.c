#include<stdio.h>
#include<math.h>
void checkarmstrong(int num){
    int n,c=0,s=0,r;
    n=num;
    while(n!=0){
        c++;
        n=n/10;
    }
    n=num;
    while(n!=0){
        r=n%10;
        s=s+(int)(pow(r,c)+0.5);
        n=n/10;
    }
    if(num==s)
    printf("armstrong");
    else
    printf("not armstrong");
}
int main(){
    int a;
    printf("enter number:");
    scanf("%d",&a);
    checkarmstrong(a);
    return 0;
}