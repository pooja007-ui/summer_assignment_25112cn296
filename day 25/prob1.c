#include<stdio.h>
int main(){
    int s1,s2,s3,i,j,k;
    printf("enter the sizes of 2 sorted arrays:");
    scanf("%d%d",&s1,&s2);
    s3=s1+s2;
    int a[s1],b[s2],c[s3];
    printf("enter 1st array elements:\n");
    for(i=0;i<s1;i++){
        scanf("%d",&a[i]);
    }
    printf("enter 2nd array elements:\n");
    for(i=0;i<s2;i++){
        scanf("%d",&b[i]);
    }
    i=j=k=0;
    while(i<s1&&j<s2){
        if(a[i]<=b[j]){
            c[k]=a[i];
            i++;
        }
        else{
            c[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<s1){
        c[k]=a[i];
        i++;
        k++;
    }
    while(j<s2){
        c[k]=b[j];
        j++;
        k++;
    }
    printf("merged array:");
    for(i=0;i<s3;i++){
        printf("%d\t",c[i]);
    }
    return 0;
}