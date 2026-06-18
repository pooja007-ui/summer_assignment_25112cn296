#include<stdio.h>
int main(){
    int n,i,b,e,m,key,loc=-1;
    printf("enter array size:");
    scanf("%d",&n);
    int a[n];
    printf("enter array elements\n:");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    b=0;
    e=n-1;
    printf("enter element to search:");
    scanf("%d",&key);
    while(b<=e){
        m=(b+e)/2;
        if(a[m]==key){
            loc=m;
            printf("element %d found at index %d",key,loc);
            break;
        }
        else if (a[m]>key){
            e=m-1;
        }
        else if(a[m]<key)
        b=m+1;
    }
    if(loc==-1)
    printf("element not found");
    return 0;
}