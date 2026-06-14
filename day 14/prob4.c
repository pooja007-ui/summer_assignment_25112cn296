#include<stdio.h>
int main(){
    int n,i;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("duplicate elements:");
    for(i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
            printf("%d\t",a[i]);
        }
    }
    return 0;
}