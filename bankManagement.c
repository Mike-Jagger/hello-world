#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
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
    system("cls");
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
    system("cls");

    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d", &add.acc_no, &add.name, &add.dob.month, &add.dob.day, &add.dob.month, add.address, add.citizenship, &add.phone, add.acc_type, &add.amt, &add.deposit.month, &add.deposit.day, &add.deposit.year) != EOF){
        printf("%6d\t %10s\t\t\t%10s\t\t\t%.0lf", add.acc_no, add.name, add.address, add.phone);
        test++;
    }
    fclose(view);
    if(test==0){
        system("cls");
        printf("\nno records\n");
    }

    view_list_invalid:
     printf("\nEnter [1] to go to the main menu or [0] to exit.\n");
        scanf("%d", &main_exit);
        system("cls");
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
        
        if(add.acc_no == upd.acc_no){

            test = 1;
            printf("\nWhich information do you want to change?\n[1] - Address\n[2] - Phone\n Ebter your choice:");
            scanf("%d", &choice); 
            system("cls");
            if(choice == 1){
                printf("Enter the new address: ");
                scanf("%s", &upd.address);
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                system("cls");
                printf("Change Saved!");
            }
        }

        else if(choice == 1){
            printf("ENter the new address: ");
            scanf("%s", &choice);
            fscanf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            system("cls");
            printf("Changes saved!");
        }

        else if(choice == 2){
            printf("Enter the new number: ");
            scanf("%lf", &upd.phone);
            fprintf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            system("cls");
            printf("Changes saved!");
        }

        else{
            printf(newrec, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
            system("cls");           
        }
        fclose(old);
        fclose(newrec);
        remove("record.dat");
        rename("new.dat", "record.dat");

        if(test != 1){
            system("cls");
            printf("\n Record not found!\n");
            edit_invalid:
              printf("Enter 0 to try again, 1 to go to the main menu or 2 to exit: ");
              scanf("%d", &main_exit);
              system("cls");
              if(main_exit == 1){
                  menu();
              }
              else if(main_exit == 2){
                  close();
              }
              else if(main_exit == 0){
                  edit();
              }
              else{
                  ("Entry is invalid!");
                  goto edit_invalid;
              }
        }
        else{
            printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
            scanf("%d", &main_exit);
            system("cls");
            if(main_exit == 1){
                menu();
            }
            else{
                close();
            }
        }

    }

}

void transact(){
    int choice, test = 0;
    FILE *old, *newrec;
    old = fopen("record.dat", "r");
    newrec = fopen("new.dat", "w");

    printf("Enter the account no. if the customer: ");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF){

        if(add.acc_no == transaction.acc_no){
            test = 1;
            if(strcmpi(add.acc_type, "fixed1") == 0){
                printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH WITH FIXED ACCOUNTS");
                fordelay(1000000000);
                system("cls");
                menu();
            }
            printf("\n\nDo you want to \n[0] - Withdraw \n[1] - Deposit? \nEnter your choice: ");
            scanf("%d", &choice);

            if(choice == 0){
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%d", transaction.amt);
                add.amt -= transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nWithdrawn successfully!");
            }
            else if(choice == 1){
                printf("Enter the amount you want to deposit:$ ");
                scanf("%d", transaction.amt);
                add.amt += transaction.amt;
                fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                printf("\n\nDeposited successfully!");
            }
        }
        else{
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
        }
    }
    fclose(newrec);
    fclose(old);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if(test != 1){
        printf("\n\nEwcord not found");
        transact_invalid:
            printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
            scanf("%d",&main_exit);
            system("cls");
            if (main_exit==0)
                transact();
            else if (main_exit==1)
                menu();
            else if (main_exit==2)
                close();
            else
            {
                printf("\nInvalid!");
                goto transact_invalid;
            }
    }
    else{
       printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
    }

}

void erase(){
    FILE *old,*newrec;
    int test=0;
    old=fopen("record.dat","r");
    newrec=fopen("new.dat","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

        else
            {test++;
            printf("\nRecord deleted successfully!\n");
            }
   }
   fclose(old);
   fclose(newrec);
   remove("record.dat");
   rename("new.dat","record.dat");
   if(test==0)
        {
            printf("\nRecord not found!!\a\a\a");
            erase_invalid:
              printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
              scanf("%d",&main_exit);

                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    erase();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            close();
        }

}

void see(){
    FILE *ptr;
    int test = 0, rate;
    int choice;
    float time;
    float intrst;

    ptr  = fopen("record.dat", "r");
    printf("\nDo you want to check by:\n[0] - Account no\n[1] - Name\nEnter your choice:");
    scanf("%d", &choice);

    if(choice == 0){
        printf("Enter the account number: ");
        scanf("%d", &check.acc_no); 
        while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year) != EOF){
            if(add.acc_no == check.acc_no){
                system("cls");
                test = 1;

                printf("\nAccount NO.: %d \nName:%s \nDOB: %d/%d/%d \nAge: %d \nAddress: %s \nCItizenship NO.: %s \nPhone number: %.0lf \nAccount Type: %s", add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type, "fixed1") == 0){
                    time = 1.0;
                    rate = 9;
                    intrst = interest(rate, add.amt, rate);
                    printf("\n\nYou will get %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else if(strcmpi(add.acc_type, "fixed2")){
                    time = 2.0;
                    rate = 11;
                    intrst = interest(rate, add.amt, rate);
                    printf("\n\nYou will get %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else if(strcmpi(add.acc_type, "fixed3")){
                    time = 3.0;
                    rate = 13;
                    intrst = interest(rate, add.amt, rate);
                    printf("\n\nYou will get %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else if(strcmpi(add.acc_type, "saving")){
                    time = (1.0/12.0);
                    rate = 8;
                    intrst = interest(rate, add.amt, rate);
                    printf("\n\nYou will get %.2f as interest on %d/%d/%d", intrst, add.deposit.month, add.deposit.day, add.deposit.year);
                }
                else if(strcmpi(add.acc_type, "current")){
                    printf("\n\nYou will get no interest");
                }
             }
        }

    }
    else if(choice == 1){
        printf("Enter your name: ");
        scanf("%s", &check.name);
        while(fscanf(ptr, "%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year) != EOF){
            if(strcmpi(add.name, check.name) == 0){
                system("cls");
                test = 1;
                printf("\nAccount No.: %d \nName: %s \nDOB: %d/%d/%d \nAge:%d \nAddress:%s \nCitizenship No:%s \nPhone number:%.0lf \nType Of Account:%s \nAmount deposited:$%.2f \nDate Of Deposit:%d/%d/%d\n\n",add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,add.citizenship,add.phone,
                add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
                if(strcmpi(add.acc_type,"fixed1")==0){
                        time=1.0;
                        rate=9;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+1);
                }
                else if(strcmpi(add.acc_type,"fixed2")==0){
                        time=2.0;
                        rate=11;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+2);

                }
                else if(strcmpi(add.acc_type,"fixed3")==0){
                        time=3.0;
                        rate=13;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d/%d/%d",intrst,add.deposit.month,add.deposit.day,add.deposit.year+3);

                }
                 else if(strcmpi(add.acc_type,"saving")==0){
                        time=(1.0/12.0);
                        rate=8;
                        intrst=interest(time,add.amt,rate);
                        printf("\n\nYou will get $.%.2f as interest on %d of every month",intrst,add.deposit.day);

                }
                 else if(strcmpi(add.acc_type,"current")==0){

                        printf("\n\nYou will get no interest\a\a");
                }
            }
        }
    }

    fclose(ptr);
    if(test!=1){
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
            printf("\nEnter 0 to try again, 1 to return to main menu or 2 to exit: ");
            scanf("%d", &main_exit);
            system("cls");
            if(main_exit == 1){
                menu();
            }
            else if(main_exit == 2){
                close();
            }
            else if(main_exit == 0){
                see();
            }
            else{
                system("cls");
                printf("\nInvalid!\a");
                goto see_invalid;
            }
    }

    else{
        printf("\nEnter 0 to go to the main menu or 1 to exit:");
        scanf("%d", &main_exit);
        if(main_exit == 0){
            system("cls");
            menu();
        }
        else{
            system("cls");
            close();
        }
    }

}

void close(){
    system("cls");
    printf("Thanks for using our services!");

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





