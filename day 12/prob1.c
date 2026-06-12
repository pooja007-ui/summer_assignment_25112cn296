#include<stdio.h>
void checkpalindrome(int num){
    int n,r,rev=0;
    n=num;
    while(n!=0){
        r= n%10;
        rev=rev*10+r;
        n=n/10;
    }
    if(rev==num)
    printf("palindrome");
    else
    printf("not palindrome");
}
int main(){
    int a;
    printf("enter a number:");
    scanf("%d",&a);
    checkpalindrome(a);
    return 0;
}