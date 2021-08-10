#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>
#include <stdbool.h>

int i, j;
int main_exit;
void menu();
int atm();
void close();
struct date{
    int month, day, year;
};

struct{
    char name[60];
    int acc_no, age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;
    }add, upd, check, rem, transaction;

float interest(float t, float amount, int rate){
    float SI;
    SI = (amount * t *rate) / 100.0;
    return(SI);
}

void fordelay(int j){
    int i, k;
    for(i = 0; i < j; i++){
        k = i;
    }
}

void new_acc(){

    int choice;
    FILE *ptr;

    ptr = fopen("record.dat", "a*");
    account_no:
    system("clear");
    printf("\t\t\t==== ADD RECORD ====");
    printf("\n\n\nEnter today's date (mm/dd/yyyy):");
    scanf("%d%d%d", &add.deposit.month, &add.deposit.day, &add.deposit.year);
    prinf("\nEnter the account number:");
    scanf("%d", &check.acc_no);
    while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
    {
        if (check.acc_no == add.acc_no){
            printf("Account already in use!");
            fordelay(1000000000);
                goto account_no;
        }
    }
    add.acc_no = check.acc_no;
        printf("\n Enter the name:");
    scanf("%s", add.name);
    print("\nEnter the date of birth(mm/dd/yyyy)");
    scanf("%d/%d/%d", &add.dob.month, &add.dob.day, &add.dob.year);
    printf("\nEnter the age:");
    scanf("%d", &add.age);
    printf("\nEnter the address:");
    scanf("%s", add.address);
    printf("\nEnter the citizenship number: ");
    scanf("%s", add.citizenship);
    printf("\n Enter the phone number:");
    scanf("%lf", &add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%f", &add.amt);
    printf("\nEnter type of account:\n #Saving\n #Current\n #fixed(for 1 year)\n fixed2(for 2 years)\n fixed3(for 3 years\n\nEnter your choice: ");
    scanf("%s", add.acc_type);
    
        fprintf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", &add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year);

    fclose(ptr);
    printf("\nAccount successfully created!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to main menu or 0 to exit:");
    scanf("%d", &main_exit);
    system("cls");
    if (main_exit == 1){
        menu();
    }
    else if(main_exit == 0){
            close();
    }
    else{
        printf("\nInvalid!\n");
        goto add_invalid;
    }
}

void view_list(){

    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    system("clear");

    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.month, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF){
        printf("%6d\t %10s\t\t\t%10s\t\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }
    fclose(view);
    if(test==0){
        system("clear");
        printf("\nno records\n");
    }

    view_list_invalid:
     printf("\nEnter [1] to go to the main menu or [0] to exit.\n");
        scanf("%d", &main_exit);
        system("clear");
        if(main_exit == 1){
            menu();
        }
        else if(main_exit == 0){
            close();
        }
        else{
            printf("\n Choice is invalid! please enter choice again:");
            goto view_list_invalid;
        }

}

void edit(){
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    print("\nEnter account number of customer whose info you want to change");
    scanf("%d", upd.acc_no);
    while(fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, add.name, &add.dob.month, &add.dob.day, &add.dob.year, &add.age, add.address, add.citizenship, add.phone, add.acc_type,add.amt, add.deposit.month, add.deposit.day, add.deposit.year) != EOF){
        
    }

}

void transact(){

}

void erase(){

}

void see(){

}

void close(){

}

void menu(){

    int choice;
    system("cls");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t[1] - Create new account\n\t\t[2] - Update information of existing account\n\t\t[3] - For transactions\n\t\t[4] - Check the details of existing account\n\t\t[5] - Removing existing account\n\t\t[6]View customer's list\n\t\t[7] - Exit\n\n\n\n\n\t\t Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1: new_acc();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:erase();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
    }

}





