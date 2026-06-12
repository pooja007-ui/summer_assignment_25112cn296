#include<stdio.h>
void fibonacci(int t){
    int a=0,b=1,c;
    printf("%d\t%d",a,b);
    for(int i=1;i<=t-2;i++){
        c=a+b;
        a=b;
        b=c;
        printf("\t%d",c);
        
    }
}
int main(){
    int a;
    printf("enter no. of terms:");
    scanf("%d",&a);
    fibonacci(a);
    return 0;
}