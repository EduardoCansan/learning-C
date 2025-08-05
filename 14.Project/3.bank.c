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

typedef struct {
    int code;
    char name[50];
    char email[50];
    char cpf[20];
    char dateBirth[20];
    char registerDate[20];

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

static Account accounts[50];
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

}

void listAccounts() {

}

float updateTotalBalance(Account account) {
    return account.balance + account.limit;
}

Account searchAccountByNumber(int number) {
    Account a;
    if(account_count > 0) {
        for (i = 0; i < account_count; i++) {
            if(accounts[i].number == number) {
                c = accounts[i];
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

}

void makeDeposit() {

}

void makeTransfer() {

}
