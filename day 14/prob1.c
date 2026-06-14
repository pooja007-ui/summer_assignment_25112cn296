#include<stdio.h>
int main(){
    int n,i,e,loc=-1;
    printf("enter no. of elements:");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        printf("a[%d]:",i);
        scanf("%d",&a[i]);
    }
    printf("enter an element:");
    scanf("%d",&e);
    for(i=0;i<n;i++){
        if(a[i]==e){
            loc=i;
            printf("element %d found at %d index",e,loc);
            break;
        }
    }
    if(loc==-1)
    printf("element not found");
    return 0;
}