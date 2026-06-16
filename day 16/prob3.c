#include<stdio.h>
int main(){
    int n,i,j,sum,f=0;
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
    printf("\nenter targeted sum:");
    scanf("%d",&sum);
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]+a[j]==sum){
                printf("required pair:%d,%d\n",a[i],a[j]);
                f=1;
            }
        }
    }
    if(!f)
    printf("no pair found for given sum");
    return 0;
}