#include<stdio.h>
int main(){
    int n,i,j,k;
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
        for(j=i+1;j<n;j++){
            if(a[i]==a[j]){
                for(k=j;k<n-1;k++)
                a[k]=a[k+1];
                n--;
                j--;
            }
        }
    }
    printf("\narray after removing duplicates:");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    return 0;
}