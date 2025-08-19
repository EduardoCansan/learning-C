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
    float totalBalence;
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
            makeTransfer();
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
    printf("Name: %sDate of birth: %sRegister: %s\n",
           client.name, client.dateBirth, client.registerDate);
}

void infoAccount(Account account) {
    printf("\nAccount number: %d\nClient: %s\nDate of birth: %s\nRegister Date: %s\nTotal Balance: %.2f\n",
           account.number, account.client.name, account.client.dateBirth,
           account.client.registerDate, account.totalBalence);
}

void createAccount() {
    Client client;

    // Date
    char registration_date[20];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    sprintf(registration_date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(client.registerDate, registration_date);

    printf("\nEnter Client Data:\n");

    printf("Client Name: ");
    scanf(" %[^\n]s", client.name);

    printf("Client Email: ");
    scanf(" %[^\n]s", client.email);

    printf("Client CPF: ");
    scanf(" %[^\n]s", client.cpf);

    printf("Client Date of Birth: ");
    scanf(" %[^\n]s", client.dateBirth);

    client_count++;

    // Create Account
    accounts[account_count].number = account_count + 1;
    accounts[account_count].client = client;
    accounts[account_count].balance = 0.0;
    accounts[account_count].limit = 0.0;
    accounts[account_count].totalBalence = updateTotalBalance(accounts[account_count]);

    printf("\nAccount Created Successfully!\n");
    printf("Account Data:\n");
    infoAccount(accounts[account_count]);
    account_count++;

    Sleep(3000);
    menu();
}

void listAccounts() {
    if (account_count > 0) {
        for (i = 0; i < account_count; i++) {
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
    for (i = 0; i < account_count; i++) {
        if (accounts[i].number == number) {
            return accounts[i];
        }
    }

    Account empty = {0};
    return empty;
}

void withdrawal(Account account, float value) {
    if (value > 0 && account.totalBalence >= value) {
        for (i = 0; i < account_count; i++) {
            if (accounts[i].number == account.number) {
                if (accounts[i].balance >= value) {
                    accounts[i].balance -= value;
                } else {
                    float remaining = value - accounts[i].balance;
                    accounts[i].balance = 0.0;
                    accounts[i].limit -= remaining;
                }
                accounts[i].totalBalence = updateTotalBalance(accounts[i]);
                printf("Withdrawal made successfully\n");
            }
        }
    } else {
        printf("***Withdrawal not made***\n");
    }

    Sleep(2000);
    menu();
}

void deposit(Account account, float value) {
    if (value > 0) {
        for (i = 0; i < account_count; i++) {
            if (accounts[i].number == account.number) {
                accounts[i].balance += value;
                accounts[i].totalBalence = updateTotalBalance(accounts[i]);
                printf("Deposit made successfully!\n");
            }
        }
    } else {
        printf("***Deposit not made***\n");
    }

    Sleep(2000);
    menu();
}

void transfer(Account origin_account, Account destiny_account, float value) {
    int oa, da;

    if (value > 0 && origin_account.totalBalence >= value) {
        for (oa = 0; oa < account_count; oa++) {
            if (accounts[oa].number == origin_account.number) {
                for (da = 0; da < account_count; da++) {
                    if (accounts[da].number == destiny_account.number) {
                        if (accounts[oa].balance >= value) {
                            accounts[oa].balance -= value;
                        } else {
                            float remaining = value - accounts[oa].balance;
                            accounts[oa].balance = 0.0;
                            accounts[oa].limit -= remaining;
                        }
                        accounts[da].balance += value;

                        accounts[oa].totalBalence = updateTotalBalance(accounts[oa]);
                        accounts[da].totalBalence = updateTotalBalance(accounts[da]);
                        printf("Transfer made successfully!\n");
                    }
                }
            }
        }
    } else {
        printf("***Transfer not made***\n");
    }

    Sleep(2000);
    menu();
}

void makeWithdrawal() {
    if (account_count > 0) {
        int number;
        printf("Enter the account number: ");
        scanf("%d", &number);

        Account account = searchAccountByNumber(number);

        if (account.number == number) {
            float value;
            printf("Enter the withdrawal amount: ");
            scanf("%f", &value);

            withdrawal(account, value);
        } else {
            printf("No account found with number %d\n", number);
            Sleep(2000);
            menu();
        }
    } else {
        printf("***There are no accounts for withdrawals yet***\n");
        Sleep(2000);
        menu();
    }
}

void makeDeposit() {
    if (account_count > 0) {
        int number;
        printf("Enter the account number: ");
        scanf("%d", &number);

        Account account = searchAccountByNumber(number);

        if (account.number == number) {
            float value;
            printf("Enter the deposit amount: ");
            scanf("%f", &value);

            deposit(account, value);
        } else {
            printf("No account found with number %d\n", number);
            Sleep(2000);
            menu();
        }
    } else {
        printf("***There are no accounts for deposit yet***\n");
        Sleep(2000);
        menu();
    }
}

void makeTransfer() {
    if (account_count > 0) {
        int origin_num, destiny_num;
        printf("Enter your account number: ");
        scanf("%d", &origin_num);

        Account origin_account = searchAccountByNumber(origin_num);

        if (origin_account.number == origin_num) {
            printf("Enter the destination account number: ");
            scanf("%d", &destiny_num);

            Account destiny_account = searchAccountByNumber(destiny_num);

            if (destiny_account.number == destiny_num) {
                float value;
                printf("Enter the transfer amount: ");
                scanf("%f", &value);

                transfer(origin_account, destiny_account, value);
            } else {
                printf("Destination account with number %d not found\n", destiny_num);
                Sleep(2000);
                menu();
            }
        } else {
            printf("Account with number %d not found\n", origin_num);
            Sleep(2000);
            menu();
        }
    } else {
        printf("***There are no accounts for transfer yet***\n");
        Sleep(2000);
        menu();
    }
}