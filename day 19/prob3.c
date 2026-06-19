#include<stdio.h>
int main(){
    int r,c,i,j;
    printf("enter the no. of rows and coloumns:");
    scanf("%d%d",&r,&c);
    int a[r][c],b[c][r];
    printf("enter 1st matrix elements:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<c;i++){
        for(j=0;j<r;j++)
        b[i][j]=a[j][i];
    }
    printf("tranpose of given matrix:\n");
    for(i=0;i<c;i++){
        for(j=0;j<r;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}