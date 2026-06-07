#include<stdio.h>
int main(){
    int i,j,b=-1,a;
    printf("enter a number:");
    scanf("%d",&a);
    printf("factors=");
    for(i=1;i<=a;i++){
        if(a%i==0){
            printf("\t%d",i);
            if(i>1){
                int isprime=1;
                for(j=2;j<=i/2;j++){
                    if(i%j==0){
                        isprime=0;
                        break;
                    }
                }
                if(isprime==1){
                    if(i>b)
                    b=i;
                }
            }
        }
    }
    printf("\nlargest prime factor=%d",b);
    return 0;
}