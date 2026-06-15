#include<stdio.h>
int main(){
    int n,i,t;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("original array:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    t=a[n-1];
    for(i=0;i<n-1;i++)
    a[i+1]=a[i];
    a[0]=t;
    printf("\nrotated array:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}