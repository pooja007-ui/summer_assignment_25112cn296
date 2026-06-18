#include<stdio.h>
int main(){
    int n,i,j,t,min;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("enter array elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("original array:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    for(i=0;i<n;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min])
            min=j;
        }
        if(min!=i){
            t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
    printf("\nsorted array:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}