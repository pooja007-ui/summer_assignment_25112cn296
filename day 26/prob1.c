#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int secnum,guess,atmpt=0,status;
    srand(time(NULL));
    secnum=(rand()%100)+1;
    printf("welcome to number guessing game!!!\n");
    printf("think of a number between 1 to 100\n");
    while(1){
        printf("enter your guess:");
        status=scanf("%d",&guess);
        if (status!=1){
            printf("invalid input. Please enter a valid number\n");
            while(getchar()!='\n');
            continue;
        }
        atmpt++;
        if(guess<secnum){
            printf("try higher\n");
        }
        else if(guess>secnum){
            printf("try lower\n");
        }
        else{
            printf("congratulations , you guesses the number %d in %d attempts",secnum,atmpt);
            break;
        }
    }
    return 0;
}