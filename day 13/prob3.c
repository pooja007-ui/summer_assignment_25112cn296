#include<stdio.h>
int main(){
    int n,i,max,min;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    max=min=a[0];
    for(i=0;i<n;i++){
        if(a[i]>max)
        max=a[i];
        if(a[i]<min)
        min=a[i];
    }
    printf("largest element:%d\n",max);
    printf("smallest elemrnt:%d",min);
    return 0;
}