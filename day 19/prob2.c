#include<stdio.h>
int main(){
    int r,c,i,j;
    printf("enter no. of rows and columns:");
    scanf("%d%d",&r,&c);
    int a[r][c],b[r][c],s[r][c];
    printf("enter elements of the 1st matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("enter the elements of 2nd matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        s[i][j]=a[i][j]-b[i][j];
    }
    printf("subtraction of matrices:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}