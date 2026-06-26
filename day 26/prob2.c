#include<stdio.h>
int main(){
    int age,status;
    printf("welcome to vote eligibility system!\n");
    while(1){
        printf("enter your age in years:");
        status=scanf("%d",&age);
        if(status!=1){
            printf("Invalid input. Please enter valid age");
            while(getchar()!='\n');
            continue;
        }
        if(age<0){
            printf("age cannot be negative. Try again\n");
            continue;
        }
        else if(age>120){
            printf("please enter realistic age\n");
            continue;
        }
        if(age>=18){
            printf("You are ELIGIBLE to vote");
        }
        else{
            printf("you are NOT ELIGIBLE to vote\n");
            printf("You will be ELIGIBLE to vote in %d years",18-age);
        }
        break;
    }
    return 0;
}