#include<stdio.h>
int main(){
    int n,i,e,f=0;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("enter element:");
    scanf("%d",&e);
    for(i=0;i<n;i++){
        if(a[i]==e)
        f++;
    }
    printf("element %d frequency:%d",e,f);
    return 0;
}