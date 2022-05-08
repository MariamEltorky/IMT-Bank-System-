#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"
#include <math.h>

long long int incrementor = 1000000000;
node head;

void CreateNewUser(void)
{
    client new_client;
    printf("Please Enter Client Full Name: ");
    gets(new_client.FullName);

    printf("\nPlease Enter Client Full Address: ");
    gets(new_client.FullAddress);

    printf("\nPlease Enter Client National ID: ");
    scanf("%lld", &new_client.NationalID);

    int count = (new_client.NationalID == 0) ? 1 : log10(new_client.NationalID) + 1;
    while (count != 14)
    {
        printf("\nPlease enter your National ID contains 14 digit: ");
        scanf("%lld", &new_client.NationalID);
        count = (new_client.NationalID == 0) ? 1 : log10(new_client.NationalID) + 1;
    }
    printf("\nPlease Enter Client Age: ");
    scanf("%d", &new_client.Age);
    new_client.BankAccountID = incrementor + 1;
    incrementor++;

    new_client.Status = "Active";
    if (new_client.Age < 21)
    {
        printf("\nPlease Enter Client Gardian National ID: ");
        scanf("%lld", &new_client.GardianNationalID);
        int count = (new_client.GardianNationalID == 0) ? 1 : log10(new_client.GardianNationalID) + 1;
        while (count != 14)
        {
            printf("\nPlease enter Gardian National ID contains 14 digit: ");
            scanf("%lld", &new_client.GardianNationalID);
            count = (new_client.GardianNationalID == 0) ? 1 : log10(new_client.GardianNationalID) + 1;
        }
    }
    else
    {
        new_client.GardianNationalID = -1;
    }
    int num = (rand() % (9999 - 1000 + 1)) + 1000;
    new_client.Password = num;

    printf("\nUser's Bank Account ID is %lld ", new_client.BankAccountID);
    printf("\nUser's Password is %d ", new_client.Password);
    AddNewUser(new_client);
    printf("\nUser Account created successfully!\n");
    fflush(stdin);
}

void main(void)
{
    int input;
    int ExitFlag = 0;
    while (ExitFlag == 0)
    {
        printf("1: Create New Account\n");
        printf("2: Open Existing Account\n");
        printf("3: Exit System\n");
        printf("Your Choice: ");
        scanf("%d", &input);
        fflush(stdin);
        switch (input)
        {
        case 1:
            CreateNewUser();
            break;
        case 3:
            printf("Thank You\nGood Bye\n");
            ExitFlag = 1;
            break;
        default:
            printf("Invalid Choice please try again\n");
            break;
        }
    }
    system("Pause");
    return;
}