#include<stdio.h>
#include<math.h>
int main(){
    int l,u,i,i1,c,r,s;
    printf("enter lower and upper limits:");
    scanf("%d%d",&l,&u);
    for(i=l;i<=u;i++){
        i1=i;
        c=0;
        s=0;
        while(i1>0){
            c++;
            i1=i1/10;
        }
        i1=i;
        while(i1>0){
            r=i1%10;
            s=s+(int)round(pow(r,c));
            i1=i1/10;
        }
        if(s==i)
        printf("%d\n",i);
    }
    return 0;
}