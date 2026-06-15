#include<stdio.h>
int main(){
    int n,i;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]",i);
        scanf("%d",&a[i]);
    }
    printf("original array:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    int t=a[0];
    for(i=0;i<n-1;i++){
        a[i]=a[i+1];
    }
    a[n-1]=t;
    printf("\nrotated array:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}