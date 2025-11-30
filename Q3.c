#include<stdio.h>
#include<string.h>

struct transaction{
	char date[15];
	char type[15];
	float amount;
};
struct account{
	char acc_type[15];
	float balance;
	float min_blnce;
	float interest;
	char creation_date[15];
	char lastTransDate[15];
	int trans_count;
	struct transaction h[50]; // h is history
};

void CreateAcc(struct account *acc);
void addTransaction(struct account *acc, char type[], float amount, char date[]);
void deposit(struct account *acc);
void withdraw(struct account *acc);
void display(struct account acc);
int main(){
	struct account acc;
	int ch;
	char choice;
	do{
		printf("1.Create Account\n");
        printf("2.Deposit\n");
        printf("3.Withdraw\n");
        printf("4.Display Details\n");
        printf("5.Exit\n");
        printf("Enter choice:\n");
        scanf("%d", &ch);
        
        switch(ch) {
            case 1:
				CreateAcc(&acc);
				break;
            case 2: 
            	deposit(&acc);
            	break;
            case 3: 
            	withdraw(&acc);
            	break;
            case 4:
            	display(acc);
            	break;
            case 5:
            	printf("Exiting...\n");
            	break;
            default:
				printf("Invalid choice!\n");
		}
		
		printf("Do you want to continue(Y/N)\n");
		scanf(" %c", &choice);
	}
	while(choice == 'Y' || choice == 'y');
	
	return 0;
}

void CreateAcc(struct account *acc){
	printf("Enter account type(Savings/Current/Fixed)\n");
	scanf("%s", acc->acc_type);
	
	if(strcmp(acc->acc_type, "Savings") == 0){
		acc->min_blnce = 1000;
		acc->interest = 0.04;
	}
	else if(strcmp(acc->acc_type, "Current") == 0){
		acc->min_blnce = 5000;
		acc->interest = 0;
	}
	else if(strcmp(acc->acc_type, "Fixed") == 0){
		acc->min_blnce = 10000;
		acc->interest = 0.07;
	}
	else{
		printf("Invalid Input!\n");
	}
	printf("Enter initial balance:\n");
	scanf("%f", &acc->balance);
	printf("Enter account creation date:\n");
	scanf("%s", acc->creation_date);
	
	strcpy(acc->lastTransDate, acc->creation_date);  
    acc->trans_count = 0;
	printf("Account Created Successfully.\n");
}

void addTransaction(struct account *acc, char type[], float amount, char date[]){
	int i = acc->trans_count;

    acc->h[i].amount = amount;
    strcpy(acc->h[i].type, type);
    strcpy(acc->h[i].date, date);

    acc->trans_count++;

    strcpy(acc->lastTransDate, date);
}

void deposit(struct account *acc){
	float amount;
    char date[15];

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    printf("Enter date: ");
    scanf("%s", date);

    acc->balance += amount;

    addTransaction(acc, "Deposit", amount, date);

    printf("Deposit Successful!\n");
}

void withdraw(struct account *acc){
    float amount;
    char date[15];

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if(acc->balance - amount < acc->min_blnce) {
        printf("Cannot go below minimum balance!\n");
        return;
    }

    printf("Enter date: ");
    scanf("%s", date);

    acc->balance -= amount;

    addTransaction(acc, "Withdrawal", amount, date);

    printf("Withdrawal Successful!\n");
}

void display(struct account acc){
	int i;
	
    printf("Account Details\n");
    printf("Account Type: %s\n", acc.acc_type);
    printf("Balance: %.2f\n", acc.balance);
    printf("Minimum Balance: %.2f\n", acc.min_blnce);
    printf("Interest Rate: %.2f\n", acc.interest);
    printf("Creation Date: %s\n", acc.creation_date);
    printf("Last Transaction Date: %s\n", acc.lastTransDate);

    printf("Transaction History\n");
    for(i = 0; i < acc.trans_count; i++) {
       printf("Transaction type: %s\n", acc.h[i].type);
       printf("Amount: %.2f\n", acc.h[i].amount);
       printf("Date: %s\n", acc.h[i].date);
    }
}

