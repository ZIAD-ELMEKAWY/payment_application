#include "List_Transaction.h"

void addTransaction(ST_transaction *t , ST_transaction *Transaction_Refrence)
{
    (Transaction_Refrence->cardHolderData.primaryAccountNumber) = (t->cardHolderData.primaryAccountNumber) ;
    (Transaction_Refrence->terminalData.transAmount) = (t->terminalData.transAmount) ;
    (Transaction_Refrence->terminalData.transactionDate) = (t->terminalData.transactionDate) ;
    (Transaction_Refrence->terminalData.maxTransAmount) = ( t->terminalData.maxTransAmount);
    t->transactionSequenceNumber++ ;
}

void displayTransaction(ST_transaction *t)
{
    printf("Card Holder Name: %s\n", t->cardHolderData.cardHolderName);
    printf("Payment Access Number: %d\n", t->cardHolderData.primaryAccountNumber);
    printf("Transaction Amount: %.2f\n", t->terminalData.transAmount);
    printf("Max Transaction Amount: %.2f\n", t->terminalData.maxTransAmount);
    printf("Transaction Date: %s\n", t->terminalData.transactionDate);
    printf("Transaction Sequence Number: %d\n", t->transactionSequenceNumber);
}
