#include<stdio.h>
int main(){
    int n,i,p=0;
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
    for(i=0;i<n;i++){
        if(a[i]!=0){
            a[p]=a[i];
            p++;
        }
    }
    while(p<n){
        a[p]=0;
        p++;
    }
    printf("\nmodified array:");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    return 0;
}