#include<stdio.h>
int main(){
    int n,i,s=0,avg;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        s=s+a[i];
    }
    avg=s/n;
    printf("sum of elements:%d\n",s);
    printf("average of elements:%d",avg);
    return 0;
}