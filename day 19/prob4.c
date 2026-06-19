#include<stdio.h>
int main(){
    int r,c,i,j,Psum=0,Ssum=0;
    printf("enter no. of rows and coloumns:");
    scanf("%d%d",&r,&c);
    int a[r][c];
    printf("enter the elements of matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
    if(r==c){
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                if(i==j)
                Psum+=a[i][j];
                if(i+j==r-1)
                Ssum+=a[i][j];
            }
        }
        printf("sum of primary diagonal elements:%d",Psum);
        printf("\nsum of secondary diagonal elements:%d",Ssum);
    }
    else
    printf("please enter a square matrix");
    return 0;
}