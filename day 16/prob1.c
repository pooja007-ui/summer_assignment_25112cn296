#include<stdio.h>
int main(){
    int n,i;
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
    int N=n+1;
    int exsum=N*(N+1)/2;
    int actsum=0;
    for(i=0;i<n;i++)
    actsum+=a[i];
    printf("\nmissing number:%d",exsum-actsum);
    return 0;
}