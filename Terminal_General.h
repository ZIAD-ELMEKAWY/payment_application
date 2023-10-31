/**
 * @file : TERMINAL_GENERAL.h
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in terminal module
 * @Date : 15 / October / 2023 ..... 10:33 AM
***/

#ifndef TERMINAL_GENERAL_H_INCLUDED
#define TERMINAL_GENERAL_H_INCLUDED

/************ Section : Includes **************/
#include "Card_General.h"

/************ Section : Macro Declarations **************/

/************ Section : Macro Function Declarations **************/

/************ Section : Data Type Declarations **************/
typedef struct ST_terminalData_t
{
    float transAmount;
    float maxTransAmount;
    uint8_t transactionDate[11];
}ST_terminalData_t;

typedef enum EN_terminalError_t
{
    TERMINAL_OK,
    WRONG_DATE,
    EXPIRED_CARD,
    INVALID_CARD,
    INVALID_AMOUNT,
    EXCEED_MAX_AMOUNT,
    INVALID_MAX_AMOUNT
} EN_terminalError_t ;

typedef enum EN_PANError_t
{
    PAN_AMEX_VALID ,
    PAN_MASTERCARD_VALID ,
    PAN_VISA_VALID ,
    PAN_INVALID
} EN_PANError_t;

/************ Section : Function Declarations **************/
static EN_terminalError_t getTransactionDate(ST_terminalData_t *termData);
static EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData);
static EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData);
static EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData);
static EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount);
static EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData); // Optional
#endif // TERMINAL_GENERAL_H_INCLUDED
