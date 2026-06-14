#include<stdio.h>
int main(){
    int n,i,max1,max2;
    printf("enter size of array:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    max1=max2=a[0];
    for(i=1;i<n;i++){
        if(a[i]>max1)
        max1=a[i];
    }
    for(i=1;i<n;i++){
        if(a[i]>max2&&a[i]!=max1)
        max2=a[i];
    }
    printf("second largest element:%d",max2);
    return 0;
}