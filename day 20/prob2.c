#include<stdio.h>
int main(){
    int r,c,i,j,count=1;
    printf("enter the no. of rows and coloumns of the matrix:");
    scanf("%d%d",&r,&c);
    if(r!=c){
        printf("a non-sqaure matrix can never be symmetric");
        return 0;
    }
    int a[r][c];
    printf("enter the matrix:\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<r;i++){
        for(j=0;j<i;j++){
            if(a[i][j]!=a[j][i]){
                count=0;
                break;
            }
        }
        if(!count)
        break;
    }
    if(count)
    printf("given matrix is symmetric");
    else
    printf("given matrix is not symmetric");
    return 0;
}