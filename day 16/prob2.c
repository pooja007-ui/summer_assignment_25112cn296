#include<stdio.h>
int main(){
    int n,i;
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
    int f=0,e=a[0],c;
    for(i=0;i<n;i++){
        c=0;
        for(int j=0;j<n;j++){
            if(a[i]==a[j])
            c++;
        }
        if(c>f){
            f=c;
            e=a[i];
        }
    }
    printf("\nelement %d has max frequency of %d",e,f);
    return 0;
}