#include<stdio.h>
int main(){
    int r,c,i,j,csum;
    printf("enter no. of rows and columns :");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("enter matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<c;i++){
        csum=0;
        for(j=0;j<r;j++){
            csum+=a[j][i];
        }
        printf(" sum of column %d:%d\n",i+1,csum);
    }
    return 0;
}