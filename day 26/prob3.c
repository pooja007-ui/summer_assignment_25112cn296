#include<stdio.h>
int main(){
    float bal=5000.00, amount;
    int choice, status;
    printf("Welcome to ATM Simulation\n");
    while(1){
        printf("ATM Menu\n");
        printf("1.Check Balance\n");
        printf("2.Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4.Exit\n");
        printf("enter your choice(1-4):");
        status=scanf("%d", &choice);
        if(status!=1){
            printf("Invalid input. Please enter valid choice number\n");
            while(getchar()!='\n');
            continue;
        }
        if(choice==1){
            printf("Current Balance:%.2f\n",bal);
        }
        else if(choice==2){
            printf("enter amount to deposit:");
            status=scanf("%f",&amount);
            if(status!=1||amount<=0){
                printf("Inalid amount. Enter a positive number\n");
                while(getchar()!='\n');
            }
            else{
                bal+=amount;
                printf("Successfully deposited %.2f. New Balance:%.2f\n",amount,bal);
            }
        }
        else if(choice==3){
            printf("enter amount to withdraw:");
            status=scanf("%f",&amount);
            if(status!=1||amount<=0){
                printf("Invalid amount. Please enter positive number\n");
                while(getchar()!='\n');
            }
            else if(amount>bal){
                printf("insufficient funds!!Your balance is only %.2f\n",bal);
            }
            else{
                bal-=amount;
                printf("Successfully withdrew %.2f. Remaining Balance:%.2f\n",amount,bal);
            }
        }
        else if(choice==4){
            printf("THANK YOU for using ATM. Goodbye!");
            break;
        }
        else{
            printf("Invalid choice. Please select a number between 1 and 4\n");
        }
    }
    return 0;
}