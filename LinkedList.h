#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

typedef struct client
{
    char FullName[100];
    char FullAddress[100];
    long long int NationalID;
    int Age;
    long long int BankAccountID;
    char *Status;
    long long int GardianNationalID;
    int Password;
    double Balance;
} client;

typedef struct Node_type node;
struct Node_type
{
    client value;
    node *Next;
};

void AddNewUser(client val);
void PrintLinkedList(void);

#endif