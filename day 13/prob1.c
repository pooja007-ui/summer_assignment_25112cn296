#include<stdio.h>
int main(){
    int n,i;
    printf("enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("elements of array:\n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;   
}