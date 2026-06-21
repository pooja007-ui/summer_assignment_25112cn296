#include<stdio.h>
int main(){
    int r,c,i,j,rsum;
    printf("enter no. of rows and coloumns :");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("enter matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<r;i++){
        rsum=0;
        for(j=0;j<c;j++){
            rsum+=a[i][j];
        }
        printf("rowise sum of row %d:%d\n",i+1,rsum);
    }
    return 0;
}