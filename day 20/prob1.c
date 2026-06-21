#include<stdio.h>
int main(){
    int r1,r2,c1,c2,i,j,k;
    printf("enter no. of rows and cplumns of 1st matrix:");
    scanf("%d%d",&r1,&c1);
    printf("enter no. of rows and coloumns of 2nd matrix:");
    scanf("%d%d",&r2,&c2);
    int a[r1][c1],b[r2][c2],c[r1][c2];
    if(c1!=r2)
    printf("multiplication not possible");
    else{
        printf("enter 1st matrix:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c1;j++)
            scanf("%d",&a[i][j]);
        }
        printf("enter 2nd matrix:\n");
        for(i=0;i<r2;i++){
            for(j=0;j<c2;j++)
            scanf("%d",&b[i][j]);
        }
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                c[i][j]=0;
                for(k=0;k<c1;k++)
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
        printf("multiplication matrix:\n");
        for(i=0;i<r1;i++){
            for(j=0;j<c2;j++){
                printf("%d\t",c[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}