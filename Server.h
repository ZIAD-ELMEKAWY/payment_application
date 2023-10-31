/**
 * @file : SERVER.h
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in server module
 * @Date : 15 / October / 2023 ..... 10:33 AM
***/

#ifndef SERVER_H_INCLUDED
#define SERVER_H_INCLUDED

/************ Section : Includes **************/
#include "Terminal_General.h"
#include "Data_Base.h"
#include "List.h"

/************ Section : Macro Declarations **************/

/************ Section : Macro Function Declarations **************/

/************ Section : Data Type Declarations **************/


typedef enum EN_transState_t
{
    APPROVED,
    DECLINED_INSUFFECIENT_FUND,
    DECLINED_STOLEN_CARD,
    FRAUD_CARD,
    INTERNAL_SERVER_ERROR
} EN_transStat_t;

typedef struct
{
    ST_cardData_t cardHolderData;
    ST_terminalData_t terminalData;
    EN_transStat_t transState;
    uint32_t transactionSequenceNumber;
} ST_transaction;


typedef enum EN_serverError_t
{
    SERVER_OK,
    SAVING_FAILED,
    TRANSACTION_NOT_FOUND,
    ACCOUNT_NOT_FOUND,
    LOW_BALANCE,
    BLOCKED_ACCOUNT
} EN_serverError_t ;

typedef enum EN_accountState_t
{
    RUNNING,
    BLOCKED
} EN_accountState_t;

typedef struct ST_accountsDB_t
{
    float balance;
    EN_accountState_t state;
    uint8_t primaryAccountNumber;
} ST_accountsDB_t;


/************ Section : Function Declarations **************/
static EN_transStat_t recieveTransactionData(ST_transaction *transData);
static EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence);
static EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence);
static EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence);
static EN_serverError_t saveTransaction(ST_transaction *transData);
static void listSavedTransactions(void);


#endif // SERVER_H_INCLUDED
