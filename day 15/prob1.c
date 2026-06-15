#include<stdio.h>
int main(){
    int n,i,t;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("original array:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=0;i<n/2;i++){
        t=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=t;
    }
    printf("\nreversed array:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}