#include<stdio.h>
int main(){
    int n1,n2,i,j;
    printf("enter 2 array sizes:");
    scanf("%d%d",&n1,&n2);
    int a[n1],b[n2],c[n1+n2];
    for(i=0;i<n1;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    for(j=0;j<n2;j++){
        printf("b[%d]:",j);
        scanf("%d",&b[j]);
    }
    printf("first array:");
    for(i=0;i<n1;i++){
        printf("%d\t",a[i]);
        c[i]=a[i];
    }
    printf("\nsecond array:");
    for(j=0;j<n2;j++){
        printf("%d\t",b[j]);
        c[i+j]=b[j];
    }
    printf("\nmerged array:");
    for(i=0;i<n1+n2;i++)
    printf("%d\t",c[i]);
    return 0;
}