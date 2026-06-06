#include<stdio.h>
#include<math.h>
int main(){
    int n,n1,r,c=0,s=0;
    printf("enter a number");
    scanf("%d",&n);
    n1=n;
    while(n>0){
        n=n/10;
        c++;
    }
    n=n1;
    while(n>0){
        r=n%10;
        s=s+pow(r,c);
        n=n/10;
    }
    if(s==n1)
    printf("armstrong number");
    else
    printf("not an armstrong number");
    return 0;
}