/**
 * @file : CARD_GENERAL.h
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in card module
 * @Date : 15 / October / 2023 ..... 10:33 AM
 **/
#ifndef CARD_GENERAL_H_INCLUDED
#define CARD_GENERAL_H_INCLUDED


/************ Section : Includes **************/
#include "Libraries.h"

/************ Section : Data Type Declarations **************/
typedef struct ST_cardData_t
{
    uint8_t cardHolderName[25];
    uint8_t primaryAccountNumber[20];
    uint8_t cardExpirationDate[6];
} ST_cardData_t;

typedef enum EN_cardError_t
{
    CARD_OK,
    WRONG_NAME,
    WRONG_EXP_DATE,
    WRONG_PAN
} EN_cardError_t;


/************ Section : Macro Declarations **************/

/************ Section : Macro Function Declarations **************/

/************ Section : Function Declarations **************/
static EN_cardError_t getCardHolderName(ST_cardData_t *cardData);
static EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData);
static EN_cardError_t getCardPAN(ST_cardData_t *cardData);
#endif // CARD_GENERAL_H_INCLUDED
