#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define MAXSIZE 10

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;
void push (int item);
int pop();
void display ();
void convert(int s);
void digit(int n);
void TwoDigit(int n1,int n2);

int i,j;
int main_exit;
void Loading();
void menu();
void CreatAccount();
void update();
void transactions();
void details();
void NumberConvert(int amount);
void removeAccount();
void view_list();
void close();

struct type{
    char name[60];
    int acc_no,age,phone,tdate,bdate,amount;
    char address[60];
}add,upd,check,rem,transaction;

int main()
{
    char pass[10],password[10]="sifat";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
    {
        printf("\n\nPassword Match!!!\nLOADING");
        Loading();
        system("cls");
        menu();
    }
    else
    {
        printf("\n\nWrong password!!\a\a\a");
        login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
        {
            system("cls");
            main();
        }
        else if (main_exit==0)
        {
            system("cls");
            close();
        }
        else
        {
            printf("\nInvalid!");
            Loading();
            system("cls");
            goto login_try;
        }
    }
    return 0;
}
void Loading()
{
    int i,j;
    for(i=1;i<6;i++)
    {
        for(j=0;j<100000000;j++)
        {
            if(j%100000000==0)
            printf(".");
        }
    }
}

void menu(void)
{   int choice;
    system("cls");
    system("color 9");
    printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);
    system("cls");
    switch(choice)
    {
        case 1:CreatAccount();
        break;
        case 2:update();
        break;
        case 3:transactions();
        break;
        case 4:details();
        break;
        case 5:removeAccount();
        break;
        case 6:view_list();
        break;
        case 7:close();
        break;
    }
}
void CreatAccount()
{
    int choice;
    FILE *ptr;

    ptr=fopen("data.txt","a+");
    account_no:
    system("cls");
    printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");

    printf("\nEnter the account number:");
    scanf("%d",&add.acc_no);
    printf("\nEnter today's date(mm/dd/yyyy):");
    scanf("%d",&add.tdate);
    printf("\nEnter the name:");
    scanf("%s",add.name);
    printf("\nEnter the date of birth(mm/dd/yyyy):");
    scanf("%d",&add.bdate);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the address:");
    scanf("%s",add.address);
    printf("\nEnter the phone number: ");
    scanf("%d",&add.phone);
    printf("\nEnter the amount to deposit:$");
    scanf("%d",&add.amount);

    fprintf(ptr,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,add.phone,add.amount);

    fclose(ptr);
    printf("\nAccount created successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
    {
        exit(1);
        close();
    }
    else
    {
        printf("\nInvalid!\a");
        goto add_invalid;
    }
}
void update()
{
    int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("NewData.txt","w");
    printf("\nEnter the account no. of the customer whose info you want to change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old,"%d %d %s %d %d %s %d %d ",&add.acc_no,&add.tdate,&add.name,&add.age,&add.bdate,&add.address,&add.phone,&add.amount)!=EOF)
    {
        if (add.acc_no==upd.acc_no)
        {
            test=1;
            printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
            scanf("%d",&choice);
            system("cls");
            if(choice==1)
            {
                printf("Enter the new address:");
                scanf("%s",upd.address);
                fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,upd.address,add.phone,add.amount);
                system("cls");
                printf("Changes saved!");
            }
            else if(choice==2)
            {
                printf("Enter the new phone number:");
                scanf("%d",&upd.phone);
                fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,upd.phone,add.amount);
                system("cls");
                printf("Changes saved!");
            }
        }
        else
            fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,add.phone,add.amount);
    }
    fclose(old);
    fclose(newrec);
    remove("data.txt");
    rename("NewData.txt","data.txt");

    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        edit_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
        {
            exit(1);
            close();
        }
        else if(main_exit==0)
            update();
        else
        {
            printf("\nInvalid!\a");
            goto edit_invalid;
        }
    }
    else
    {
        printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(1);
    }
}

void transactions()
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("data.txt","r");
    newrec=fopen("NewData.txt","w");

    printf("Enter the account no. of the customer:");
    scanf("%d",&transaction.acc_no);
    while (fscanf(old,"%d %d %s %d %d %s %d %d ",&add.acc_no,&add.tdate,&add.name,&add.age,&add.bdate,&add.address,&add.phone,&add.amount)!=EOF)
    {
        if(add.acc_no==transaction.acc_no)
        {
            test=1;
            printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
            scanf("%d",&choice);
            if (choice==1)
            {
                printf("Enter the amount you want to deposit:$ ");
                scanf("%d",&transaction.amount);
                add.amount=add.amount+transaction.amount;
                fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,add.phone,add.amount);
                printf("\n\nDeposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw:$ ");
                scanf("%d",&transaction.amount);
                add.amount=add.amount-transaction.amount;
                fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,add.phone,add.amount);
                printf("\n\nWithdrawn successfully!");
            }
        }
        else
        {
             fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,add.phone,add.amount);
        }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("NewData.txt","data.txt");
   if(test!=1)
   {
      printf("\n\nRecord not found!!");
      transact_invalid:
      printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
      scanf("%d",&main_exit);
      system("cls");
      if (main_exit==0)
        transactions();
      else if (main_exit==1)
            menu();
      else if (main_exit==2)
            exit(1);
      else
      {
          printf("\nInvalid!");
          goto transact_invalid;
      }
   }
   else
   {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
        {
            exit(1);
            close();
        }
   }
}
void details()
{
    FILE *ptr;
    int test=0,rate;
    int choice;
    float time;
    float intrst;
    ptr=fopen("data.txt","r");
    printf("Enter the account number:");
    scanf("%d",&check.acc_no);

    while (fscanf(ptr,"%d %d %s %d %d %s %d %d ",&add.acc_no,&add.tdate,&add.name,&add.age,&add.bdate,&add.address,&add.phone,&add.amount)!=EOF)
    {
        if(add.acc_no==check.acc_no)
        {   system("cls");
            test=1;
            printf("\nAccount NO:%d\nName:%s \nAge:%d \nAddress:%s \nPhone number:%d \nAmount:",add.acc_no,add.name,add.age,add.address,add.phone);
            NumberConvert(add.amount);
        }
    }
    fclose(ptr);
    if(test!=1)
    {
        system("cls");
        printf("\nRecord not found!!\a\a\a");
        see_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if (main_exit==2)
            exit(1);
        else if(main_exit==0)
            details();
        else
        {
            system("cls");
            printf("\nInvalid!\a");
            goto see_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
    }
    if (main_exit==1)
    {
        system("cls");
        menu();
    }
    else
    {
        system("cls");
        exit(1);
    }
}
void removeAccount()
{
    FILE *old,*newrec;
    int test=0;
    old=fopen("data.txt","r");
    newrec=fopen("newdata.txt","w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d",&rem.acc_no);
    while (fscanf(old,"%d %d %s %d %d %s %d %d ",&add.acc_no,&add.tdate,&add.name,&add.age,&add.bdate,&add.address,&add.phone,&add.amount)!=EOF)
   {
        if(add.acc_no!=rem.acc_no)
            fprintf(newrec,"%d %d %s %d %d %s %d %d \n",add.acc_no,add.tdate,add.name,add.bdate,add.age,add.address,upd.phone,add.amount);
        else
        {
             test++;
             printf("\nRecord deleted successfully!\n");
        }
   }
   fclose(old);
   fclose(newrec);
   remove("data.txt");
   rename("newdata.txt","data.txt");
   if(test==0)
    {
        printf("\nRecord not found!!\a\a\a");
        erase_invalid:
        printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
        scanf("%d",&main_exit);

        if (main_exit==1)
            menu();
        else if (main_exit==2)
        {
            system("cls");
            exit(1);
        }
        else if(main_exit==0)
            removeAccount();
        else
        {
            printf("\nInvalid!\a");
            goto erase_invalid;
        }
    }
    else
    {
        printf("\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else
            exit(1);
    }
}
void view_list()
{
    FILE *view;
    view=fopen("data.txt","r");
    int test=0;
    system("cls");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");
    while(fscanf(view,"%d %d %s %d %d %s %d %d ",&add.acc_no,&add.tdate,&add.name,&add.age,&add.bdate,&add.address,&add.phone,&add.amount)!=EOF)
       {
           printf("\n%d\t %s\t\t\t%s\t\t%d",add.acc_no,add.name,add.address,add.phone);
           test++;
       }
    fclose(view);

    if (test==0)
        {   system("cls");
            printf("\nNO RECORDS!!\n");
        }

    view_list_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
            menu();
        else if(main_exit==0)
        {
            close();
            exit(1);
        }
        else
        {
            printf("\nInvalid!\a");
            goto view_list_invalid;
        }
}
void close()
{
    printf("\nThis Project Is Developed by \nMD:HABIBUR RAHMAN SIFAT\nID:011 152 028\n");
}
///####################################Convert Code##################################################
void NumberConvert(int amount)
{
    s.top = -1;
    int len,i=0,j=0;
    char num1[10],num2[10];
    sprintf(num1,"%d",amount);
    len=strlen(num1);
    while(i<len)
    {
        push(num1[i]);
        i++;
    }
    i=i-1;
    while(i>=0)
    {
        num2[j]=pop();
        i--;
        j++;
    }
    i=0;
    while(i<len)
    {
        push(num2[i]);
        i++;
    }
    convert(i);
}
void push (int item)
{
    if (s.top+1 == MAXSIZE)
    {
        printf ("Stack is Full\n");
    }
    else
    {
        s.top++;
        s.stk[s.top] = item;
    }
}

int pop ()
{
    int num;
    if (s.top == - 1)
    {
        printf ("Stack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        //printf ("poped element is = %c\n", s.stk[s.top]);
        s.stk[s.top]=0;
        s.top--;
    }
    return(num);
}

void display ()
{
    int i;
    if (s.top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\nThe status of the stack is\n");
        for (i = s.top; i >= 0; i--)
        {
            printf ("%c\n", s.stk[i]);
        }
    }
    printf ("\n");
}

void convert(int s)
{
    int n1,n2,n3,n4,n5,n6,n7,n8;
    switch(s)
        {
            case 1 :
                 n1=pop();
                 digit(n1);
                 break;
            case 2 :
                 n1=pop();
                 n2=pop();
                 TwoDigit(n1,n2);
                 break;
            case 3 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 digit(n1);
                 printf(" Hundred And ");
                 TwoDigit(n2,n3);
                 break;
            case 4 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 n4=pop();
                 digit(n1);
                 printf(" Thousand");
                 digit(n2);
                 printf(" Hundred And ");
                 TwoDigit(n3,n4);
                 break;
            case 5 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 n4=pop();
                 n5=pop();
                 TwoDigit(n1,n2);
                 printf(" Thousand");
                 digit(n3);
                 printf(" Hundred And ");
                 TwoDigit(n4,n5);
                 break;
            case 6 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 n4=pop();
                 n5=pop();
                 n6=pop();
                 digit(n1);
                 printf(" Lakh ");
                 TwoDigit(n2,n3);
                 printf(" Thousand ");
                 digit(n4);
                 printf(" Hundred And ");
                 TwoDigit(n5,n6);
                 break;
            case 7 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 n4=pop();
                 n5=pop();
                 n6=pop();
                 n7=pop();
                 TwoDigit(n1,n2);
                 printf(" Lakh ");
                 TwoDigit(n3,n4);
                 printf(" Thousand ");
                 digit(n5);
                 printf(" Hundred And ");
                 TwoDigit(n6,n7);
                 break;
            case 8 :
                 n1=pop();
                 n2=pop();
                 n3=pop();
                 n4=pop();
                 n5=pop();
                 n6=pop();
                 n7=pop();
                 n8=pop();
                 digit(n1);
                 printf(" Crore ");
                 TwoDigit(n2,n3);
                 printf(" Lakh ");
                 TwoDigit(n4,n5);
                 printf(" Thousand ");
                 digit(n6);
                 printf(" Hundred And ");
                 TwoDigit(n7,n8);
                 break;
        }
}
void digit(int n)
{
    switch(n)
         {
            case 48:
                 break;
            case 49 :
                 printf(" One");
                 break;
            case 50 :
                 printf(" Two");
                 break;
            case 51 :
                 printf(" Three");
                 break;
            case 52 :
                 printf(" Four");
                 break;
            case 53 :
                 printf(" Five");
                 break;
            case 54 :
                 printf(" Six");
                 break;
            case 55 :
                 printf(" Seven");
                 break;
            case 56 :
                 printf(" Eight\n");
                 break;
            case 57 :
                 printf(" Nine");
                 break;
         }
}

void TwoDigit(int n1,int n2)
{
    if(n1==49)
     {
         switch(n2)
         {
            case 48:
                 printf("Ten");
                 break;
            case 49 :
                 printf("Eleven ");
                 break;
            case 50 :
                 printf("Twelve");
                 break;
            case 51 :
                 printf("Thirteen");
                 break;
            case 52 :
                 printf("Fourteen");
                 break;
            case 53 :
                 printf("Fifteen");
                 break;
            case 54 :
                 printf("Sixteen");
                 break;
            case 55 :
                 printf("Seventeen");
                 break;
            case 56 :
                 printf("Eighteen");
                 break;
            case 57 :
                 printf("Nineteen");
                 break;
         }
     }
     else
     {
        switch(n1)
         {
            case 50 :
                 printf("Twenty");
                 digit(n2);
                 break;
            case 51 :
                 printf("Thirty");
                 digit(n2);
                 break;
            case 52 :
                 printf("Fourty");
                 digit(n2);
                 break;
            case 53 :
                 printf("Fifty");
                 digit(n2);
                 break;
            case 54 :
                 printf("Sixty");
                 digit(n2);
                 break;
            case 55 :
                 printf("Seventy");
                 digit(n2);
                 break;
            case 56 :
                 printf("Eighty");
                 digit(n2);
                 break;
            case 57 :
                 printf("Ninety");
                 digit(n2);
                 break;
         }
     }
}
