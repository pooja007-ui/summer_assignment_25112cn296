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
        int ap=0;
        for(int k=0;k<i;k++){
            if(a[i]==a[k]){
                ap=1;
                break;
            }
        }
        if(!ap){
            for(int j=i+1;j<n;j++){
                if(a[i]==a[j]){
                    printf("%d\t",a[i]);
                    break;
                }
            }
        }
    }
    return 0;
}