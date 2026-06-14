#include<stdio.h>
int main(){
    int n,i,oc=0,ec=0;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if(a[i]%2==0)
        ec++;
        else
        oc++;
    }
    printf("no. of even elements:%d\n",ec);
    printf("no. of odd elements:%d",oc);
    return 0;
}