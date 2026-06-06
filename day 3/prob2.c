#include<stdio.h>
int main(){
    int l,u,i,j,c;
    printf("enter the lower and upper limits:");
    scanf("%d%d",&l,&u);
    for(i=l;i<=u;i++){
        c=0;
        for(j=2;j<=i/2;j++){
            if(i%j==0){
                c=c+1;
                break;
            }
        }
        if(c==0)
        printf("%d\n",i);
   }
    return 0;
}