#include<stdio.h>
int main(){
    int n1,n2,i,j;
    printf("enter the 1st array size:");
    scanf("%d",&n1);
    int a[n1];
    printf("enter 1st array elements:\n");
    for(i=0;i<n1;i++)
    scanf("%d",&a[i]);
    printf("enter 2nd array size:");
    scanf("%d",&n2);
    int b[n2];
    printf("enter 2nd array elements:\n");
    for(i=0;i<n2;i++)
    scanf("%d",&b[i]);
    for(i=0;i<n1;i++){
        for(j=0;j<n2;j++){
            if(a[i]==b[j]){
                printf("%d",a[i]);
                break;
            }
        }
    }
    return 0;
}