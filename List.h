/**
 * @file : LIST.H
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in List module
 * @Date : 20 / October / 2023 .....
 **/

#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/************ Section : Includes **************/
#include "Server.h"

/************ Section : Macro Declarations **************/
typedef struct Node {
    ST_accountsDB_t Account ;
    struct Node* next;
} Node;

// Define the structure for the linked list
typedef struct LinkedList {
    Node* head;
} LinkedList;
/************ Section : Macro Function Declarations **************/

/************ Section : Data Type Declarations **************/
void addAccount(LinkedList* List, int PAN , float Balance ) ;
int searchAccount(LinkedList* List, int accountNumber);
void deleteAccount(LinkedList* List, int accountNumber);

//static void Traverse_List(List *pl , void (* Visit)(List_AccountDB_t));
#endif // LIST_H_INCLUDED
