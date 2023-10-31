/**
 * @file : LIST.c
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in list module
 * @Date : 20 / October / 2023 .....
 **/
/************ Section : Includes **************/
#include "List.h"
#include "Server.h"
/************ Section : Helper Function Declarations **************/

/************ Section : Helper Function Definitions **************/

/************ Section : Global Variable Definitions **************/

/************ Section : Function Definitions **************/

// Function to add an account to the linked list
void addAccount(LinkedList* List, int PAN , float Balance ) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->Account.primaryAccountNumber = PAN;
    newNode->Account.balance = Balance ;
    newNode->next = NULL;

    if (List->head == NULL) {
        List->head = newNode;
    } else {
        Node* temp = List->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to search for an account in the linked list
/*Return Status
* 0 : Account is founded
* 1 : Account is not founded
*/
int searchAccount(LinkedList* List, int accountNumber) {
    Node* temp = List->head;
    while (temp != NULL) {
        if (temp->Account.primaryAccountNumber == accountNumber) {
            return 0;
        }
        temp = temp->next;
    }
    return 1;
}

// Function to delete an account from the linked list
void deleteAccount(LinkedList* List, int accountNumber) {
    Node* temp = List->head;
    Node* prev = NULL;

    if (temp != NULL && temp->Account.primaryAccountNumber == accountNumber) {
        List->head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->Account.primaryAccountNumber != accountNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Account number not found.\n");
    } else {
        prev->next = temp->next;
        free(temp);
    }
}
