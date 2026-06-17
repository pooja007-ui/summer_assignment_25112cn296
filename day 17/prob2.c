#include<stdio.h>
int main(){
    int n1,n2,usize=0,uarr[100],i,j,f;
    printf("enter 1st array size:");
    scanf("%d",&n1);
    int a[n1];
    printf("enter elements of 1st array:\n");
    for(i=0;i<n1;i++){
        scanf("%d",&a[i]);
        uarr[usize++]=a[i];
    }
    printf("enter 2nd array size:");
    scanf("%d",&n2);
    int b[n2];
    printf("enter elements of 2nd array:\n");
    for(i=0;i<n2;i++){
        scanf("%d",&b[i]);
        f=0;
        for(j=0;j<usize;j++){
            if(b[i]==uarr[j]){
                f=1;
                break;
            }
        }
        if(!f)
        uarr[usize++]=b[i];
    }
    printf("union of arrays:");
    for(i=0;i<usize;i++)
    printf("%d\t",uarr[i]);
    return 0;
}
