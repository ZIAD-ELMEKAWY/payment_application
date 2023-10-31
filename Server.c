/**
 * @file :  SERVER.c
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in server module
 * @Date : 15 / October / 2023 ..... 10:33 AM
 **/


/************ Section : Includes **************/
#include "Server.h"
#include "List.h"
/************ Section : Helper Function Declarations **************/
static EN_PANError_t PANLuhnCheck(uint64_t PANNumber);
/************ Section : Helper Function Definitions **************/


/************ Section : Global Variable Definitions **************/
LinkedList Account_1 ;
ST_transaction Transaction_1 ;
/************ Section : Function Definitions **************/
static EN_transStat_t recieveTransactionData(ST_transaction *transData)
{
    EN_transStat_t ret = APPROVED ;
    addAccount(&Account_1 , transData->cardHolderData.primaryAccountNumber , transData->terminalData.transAmount );
    if(transData != NULL)
    {
        if((isBlockedAccount(&(transData->cardHolderData)) == 5 ) && (isAmountAvailable(&(transData->terminalData) , &(transData->cardHolderData)) == 4) )
        {
            ret = FRAUD_CARD ;
        }
    }
    else
    {
        ret = FRAUD_CARD ;
    }
}


static EN_serverError_t isValidAccount(ST_cardData_t *cardData, ST_accountsDB_t* accountRefrence)
{
    EN_serverError_t ret = SERVER_OK ;
    int ret_1 = 0 ;
    ret_1 = searchAccount(&Account_1 , cardData->primaryAccountNumber) ;
    if(ret_1 == 0)
    {
        Account_1.head->Account.balance = accountRefrence->balance ;
        Account_1.head->Account.primaryAccountNumber = accountRefrence->primaryAccountNumber ;
        Account_1.head->Account.state = accountRefrence->state ;
        ret = SERVER_OK ;
    }
    else
    {
        ret = ACCOUNT_NOT_FOUND ;
    }
    return ret ;
}

static EN_serverError_t isBlockedAccount(ST_accountsDB_t *accountRefrence)
{
    EN_serverError_t ret = SERVER_OK ;
    if(accountRefrence == NULL )
    {
        ret = BLOCKED_ACCOUNT ;
    }
    else
    {
        if(accountRefrence->state == BLOCKED)
        {
            ret = BLOCKED_ACCOUNT ;
        }
        else
        {
            ret = SERVER_OK ;
        }
    }
    return ret ;
}

static EN_serverError_t isAmountAvailable(ST_terminalData_t *termData, ST_accountsDB_t* accountRefrence)
{
    EN_serverError_t ret = SERVER_OK ;
    if(termData == NULL || accountRefrence == NULL)
    {
        ret = LOW_BALANCE ;
    }
    else
    {
        if(termData->transAmount < accountRefrence->balance)
        {
            ret = LOW_BALANCE ;
        }
        else
        {
            ret = SERVER_OK ;
        }
    }
    return ret ;
}

static EN_serverError_t saveTransaction(ST_transaction *transData)
{
    displayTransaction(&transData) ;
}


