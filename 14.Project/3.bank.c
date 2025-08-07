/*
    Create an application that, on startup, presents a menu of actions the user can perform in a bank:
        Create a new accoun, Make a withdrawal, Make a deposit, Make a transfer, 
        List all accounts, Exit the system

    The system should handle each operation appropriately and display clear messages 
    to the user after each action.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#define ACCOUNT_DATA_SIZE 50
#define CLIENT_NAME_SIZE 50
#define CLIENT_EMAIL_SIZE 50
#define CLIENT_CPF_SIZE 20
#define CLIENT_BIRTH_SIZE 20
#define CLIENT_DATE_SIZE 20

typedef struct {
    int code;
    char name[CLIENT_NAME_SIZE];
    char email[CLIENT_EMAIL_SIZE];
    char cpf[CLIENT_CPF_SIZE];
    char dateBirth[CLIENT_BIRTH_SIZE];
    char registerDate[CLIENT_DATE_SIZE];

} Client;

typedef struct {
    int number;
    Client client;
    float balance;
    float limit;
    float totalBalence; // balance + limit

} Account;

void menu();
void infoClient(Client client);
void infoAccount(Account account);
void createAccount();
void makeWithdrawal();
void makeDeposit();
void makeTransfer();
void listAccounts();
float updateTotalBalance(Account account);
Account searchAccountByNumber(int number);
void withdrawal(Account account, float value);
void deposit(Account account, float value);
void transfer(Account origin_account, Account destiny_account, float value);

static Account accounts[ACCOUNT_DATA_SIZE];
static int account_count = 0;
static int client_count = 0;

int i;

int main() {

    menu();
    
    return 0;
}

void menu() {

    int option;
    printf("\n==============================\n");
    printf("============ BANK ============\n");
    printf("==============================\n");

    printf("Select an option:\n");
    printf("[1] - Create Account\n");
    printf("[2] - Make Withdrawal\n");
    printf("[3] - Make Deposit\n");
    printf("[4] - Make Transfer\n");
    printf("[5] - List Accounts\n");
    printf("[6] - Exit\n");

    printf("\nOption: ");
    scanf("%d", &option);

    switch (option) {
    case 1:
        createAccount();
        break;
    case 2:
        makeWithdrawal();
        break;
    case 3:
        makeDeposit();
        break;
    case 4:
        makeDeposit();
        break;
    case 5:
        listAccounts();
        break;
    case 6:
        printf("Thank you for your trust!\n");
        Sleep(2000);
        exit(0);

    default:
        printf("*** Invalid Option ***\n");
        Sleep(2000);
        menu();
    }
}

void infoClient(Client client) {
    printf("Code: %d, \nName: %s \nDate of birth: %s \nRegister: %s\n",
    strtok(client.name, "\n"), strtok(client.dateBirth, "\n"), strtok(client.dateBirth, "\n"));
}

void infoAccount(Account account) {
    printf("Account number: %s \nClient: %s \nDate of birth: %s \nRegister Date: %s \nTotal Balance: %2.f\n",
    account.number, strtok(account.client.name, "\n"), strtok(account.client.dateBirth, "\n"), 
    strtok(account.client.registerDate, "\n"), account.totalBalence);
}

void createAccount() {
    Client client;

    // Registration date
    char day[3];
    char month[3];
    char year[5];
    char registration_date[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // day
    if(tm.tm_mday < 10) {
        sprintf(day, "0%d", tm.tm_mday); // transform number in 1 to 01, till 10
    
    } else {
        sprintf(day, "%d", tm.tm_mday);
    }

    // month
    if((tm.tm_mon + 1) < 10) { // +1 cause goes 0 to 11 (not 1 to 12)
        sprintf(month, "0%d", tm.tm_mon + 1);
    
    } else {
        sprintf(month, "%d", tm.tm_mon + 1);
    }

    //year
    sprintf(year, "%d", tm.tm_year + 1900); // default (current year - 1900)

    strcpy(registration_date, "");
    strcat(registration_date, day);
    strcat(registration_date, "/");
    strcat(registration_date, month);
    strcat(registration_date, "/");
    strcat(registration_date, year);
    strcat(registration_date, "\0"); // finish
    strcpy(client.registerDate, registration_date);

    //Creating Client
    printf("Enter Client Data: \n");

    printf("\nClient Name: \n");
    fgets(client.name, CLIENT_NAME_SIZE, stdin);

    printf("Client Email: \n");
    fgets(client.email, CLIENT_EMAIL_SIZE, stdin);

    printf("Client CPF: \n");
    fgets(client.cpf, CLIENT_CPF_SIZE, stdin);

    printf("Client Date Birth: \n");
    fgets(client.dateBirth, CLIENT_BIRTH_SIZE, stdin);

    client_count++;

    // Creating Account
    accounts[account_count].number = account_count + 1;
    accounts[account_count].client = client;
    accounts[account_count].balance = 0.0;
    accounts[account_count].limit = 0.0;
    accounts[account_count].totalBalence = updateTotalBalance(accounts[account_count]);

    printf("\nAccount Created Successfully!\n");
    printf("\nAccount Data: \n");
    infoAccount(accounts[account_count]);
    account_count++;

    Sleep(5000);
}

void listAccounts() {
    if(account_count > 0) {
        for(i = 0; i < account_count; i++) {
            infoAccount(accounts[i]);
            printf("\n");
            Sleep(1000);
        }

    } else {
        printf("***There are no registered accounts yet***\n");
    }
    Sleep(2000);
    menu();
}

float updateTotalBalance(Account account) {
    return account.balance + account.limit;
}

Account searchAccountByNumber(int number) {
    Account a;
    if(account_count > 0) {
        for (i = 0; i < account_count; i++) {
            if(accounts[i].number == number) {
                a = accounts[i];
            }
        }    
    }
    return a;
}

void withdrawal(Account account, float value) {
    if(value > 0 && account.totalBalence >= value) {
        for(i = 0; i < account_count; i++) {
            if(accounts[i].number == account.number) {
                if(accounts[i].balance >= value) {
                    accounts[i].balance = accounts[i].balance - value;
                    accounts[i].totalBalence = updateTotalBalance(accounts[i]);
                    printf("Withdrawal made successfully\n");
                
                } else {
                    float remaining = accounts[i].balance - value;
                    accounts[i].limit = accounts[i].limit - remaining;
                    accounts[i].balance = 0.0;
                    accounts[i].totalBalence = updateTotalBalance(accounts[i]);
                    printf("Withdrawal made successfully\n");
                }
            }
        }
    } else {
        printf("***Withdrawal not made***\n");
    }
}

void deposit(Account account, float value) {
    if(value > 0) {
        for(i = 0; i < account_count; i++) {
            if(accounts[i].number == account.number) {
                accounts[i].balance = accounts[i].balance + value;
                accounts[i].totalBalence = updateTotalBalance(accounts[i]);
                printf("Deposit made successfully!\n");
            }
        }
    } else {
        printf("***Deposit not made***\n");
    }

}

void transfer(Account origin_account, Account destiny_account, float value) {
    int oa, da; //oa => origin account // da => destiny account
    
    if(value > 0 && origin_account.totalBalence >= value) {
        for(oa = 0; oa < account_count; oa++) {
            if(accounts[oa].number == origin_account.number) {
                for(da = 0; da < account_count; da++) {
                    if(accounts[da].number == destiny_account.number) {
                        if(accounts[oa].balance >= value) {

                            accounts[oa].balance = accounts[oa].balance - value;
                            accounts[da].balance = accounts[da].balance + value;

                            accounts[oa].totalBalence = updateTotalBalance(accounts[oa]);
                            accounts[da].totalBalence = updateTotalBalance(accounts[da]);
                            printf("Transfer made successfully!\n");
                        
                        } else {
                            float remaining = accounts[oa].balance - value;
                            accounts[oa].limit = accounts[oa].limit + remaining;
                            accounts[oa].balance = 0.0;
                            accounts[da].balance = accounts[da].balance + value;
                            accounts[oa].totalBalence = updateTotalBalance(accounts[oa]);
                            accounts[da].totalBalence = updateTotalBalance(accounts[da]);
                            printf("Transfer made successfully!\n");
                        }
                    }
                }
            }
        }
    } else {
        printf("***Transfer not made***\n");
    }

}

void makeWithdrawal() {
    if(account_count > 0) {
        int number;
        printf("Enter the account number: \n");
        scanf("%d", &number);

        Account account = searchAccountByNumber(number);

        if(account.number == number) {
            float value;
            printf("Inform the withdrawal amount: \n");
            scanf("%d", &value);

            withdrawal(account, value);
        
        } else {
            printf("No account was found with the number %d\n", number);
        }
    
    } else {
        printf("***There are no accounts for withdrawals yet***\n");
        Sleep(2000);
        menu();
    }
}

void makeDeposit() {
    if(account_count > 0) {
        int number;
        printf("Enter the account number: \n");
        scanf("%d", &number);

        Account account = searchAccountByNumber(number);

        if(account.number == number) {
            float value;
            printf("Inform the deposit amount: \n");
            scanf("%d", &value);

            deposit(account, value);
        
        } else {
            printf("No account was found with the number %d\n", number);
        }
    
    } else {
        printf("***There are no accounts for deposit yet***\n");
        Sleep(2000);
        menu();
    }
}

void makeTransfer() {
    if(account_count > 0) {
        int origin_num, destiny_num;
        printf("Enter your account number: \n");
        scanf("%d", origin_num);

        Account origin_account = searchAccountByNumber(origin_num);

        if(origin_account.number == origin_num) {
            printf("Enter the destination account number: \n");
            scanf("%d", &destiny_num);

            Account destiny_account = searchAccountByNumber(destiny_num);

            if(destiny_account.number == destiny_num) {
                float value;
                printf("Inform the amount for the transfer: \n");
                scanf("%f", &value);
                
                transfer(origin_account, destiny_account, value);

            } else {
                printf("The destination account with number %d was not found\n", destiny_num);
            }

        } else {
            printf("The account with number %d was not found\n", origin_num);
        }


    } else {
        printf("***There are no accounts for transfer yet***\n");
    }
    Sleep(2000);
    menu();
}