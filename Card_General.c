/**
 * @file : CARD_GENERAL.c
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in card module
 * @Date : 15 / October / 2023 ..... 10:33 AM
 **/


/******* Format for file for Card module Start ****************/
/**
*   1.
*   Name :
*   Expiration Date :
*   PAN :
**/
/******* Format for file for Card module End   ****************/

/************ Section : Includes **************/
#include "Card_General.h"
/************ Section : Helper Function Declarations **************/

/************ Section : Helper Function Definitions **************/

/************ Section : Global Variable Definitions **************/

/************ Section : Function Definitions **************/
static EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{
    uint8_t counter = 0 ;
    uint8_t Name_Length = 0 ;
    EN_cardError_t ret = CARD_OK ;

    printf("Enter your name : ");
    gets(cardData->cardHolderName);
    Name_Length = strlen(cardData->cardHolderName);
    if(cardData->cardHolderName == NULL || Name_Length <20 || Name_Length >24 )
    {
        ret = WRONG_NAME ;
    }
    else
    {
        counter++ ;
        ret = CARD_OK ;
    }
    return ret ;
}

static EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    uint8_t ExpiryDateLength = 0;
    EN_cardError_t ret = CARD_OK ;
    if (cardData != NULL )
    {
        printf("Enter your Expiry Date in the format [ MM/YY ] : ");
        gets(cardData->cardExpirationDate);
        ExpiryDateLength = strlen(cardData->cardExpirationDate);
        if((NULL == cardData->cardExpirationDate) || (ExpiryDateLength < 5) || (ExpiryDateLength > 5 )|| ((cardData->cardExpirationDate[2]) != '/'))
        {
            ret = WRONG_EXP_DATE ;
        }
        else
        {
            ret = CARD_OK ;
        }
    }
    else
    {
        ret = WRONG_EXP_DATE ;
    }
    return ret ;
}

static EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    uint8_t PANLength = 0;
    EN_cardError_t ret = CARD_OK ;

    if (cardData != NULL )
    {
        printf("Enter your PAN (Primary Account Number) : ");
        gets(cardData->primaryAccountNumber);
        PANLength = strlen(cardData->primaryAccountNumber);
        if((NULL == cardData->primaryAccountNumber) || (PANLength < 16) || (PANLength > 19 ))
        {
            ret = WRONG_PAN ;
        }
        else
        {
            ret = CARD_OK ;
        }
    }
    else
    {
        ret = WRONG_PAN ;
    }
    return ret ;
}

