/**
 * @file : TERMINAL_GENERAL.c
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in terminal module
 * @Date : 15 / October / 2023 ..... 10:33 AM
 **/


/************ Section : Includes **************/
#include "Terminal_General.h"

#define Terminal_Max_Allowed_Amount 10000
/************ Section : Helper Function Declarations **************/
static EN_PANError_t PANLuhnCheck(uint64_t PANNumber);
/************ Section : Helper Function Definitions **************/
static EN_PANError_t PANLuhnCheck(uint64_t PANNumber)
{
    long int cc;
    int digit_count = 0;
    int sum = 0;
    EN_PANError_t PANRet;

    //variables that store the first numbers of the cards
    int amex = cc / pow(10, 13);
    int master = cc / pow(10, 14);
    int visa[2];
    visa[0] = cc / pow(10, 12);
    visa[1] = cc / pow(10, 15);

    //checksum for the luhn algorithm
    while (cc > 0)
    {
        int digit = cc % 10;
        cc /= 10;
        digit_count++;

        if (digit_count % 2 == 0)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }

        sum += digit;
    }

    //statements to check if cards are valid,american express, visa, mastercard or invalid
    //if the result of sum ends with 0 then this is a valid card from there we check the type of card it is
    if (sum % 10 == 0)
    {
        if (amex == 34 || amex == 37)
        {
            PANRet = PAN_AMEX_VALID;
        }
        else if (master == 51 || master == 52 || master == 53 || master == 54 || master == 55)
        {
            PANRet = PAN_MASTERCARD_VALID;
        }
        else if (visa[0] == 4 || visa[1] == 4)
        {
            PANRet = PAN_VISA_VALID;
        }
        else
        {
            PANRet = PAN_INVALID ;
        }
    }
    else
    {
        PANRet = PAN_INVALID ;
    }
    return PANRet ;
}

/************ Section : Function Definitions **************/
static EN_terminalError_t getTransactionDate(ST_terminalData_t *termData)
{
    EN_terminalError_t ret = TERMINAL_OK ;
    uint8_t TransactionDateLength = 0;

    if(termData != NULL)
    {
        printf("Enter Transaction Date in the format [DD/MM/YYYY] : ");
        gets(termData->transactionDate);
        TransactionDateLength = strlen(termData->transactionDate);
        if((NULL == termData->transactionDate) || (TransactionDateLength < 10) || (termData->transactionDate[2] != '/') || (termData->transactionDate[5] != '/'))
        {
            ret = WRONG_DATE ;
        }
        else
        {
            ret = TERMINAL_OK ;
        }
    }
    else
    {

        ret = WRONG_DATE ;
    }
    return ret ;
}

static EN_terminalError_t isCardExpired(ST_cardData_t *cardData, ST_terminalData_t* termData)
{
    EN_terminalError_t ret = TERMINAL_OK ;
    uint8_t Compare = 0;

    Compare = memcmp((cardData->cardExpirationDate) , (termData->transactionDate) , 5);
    if(termData != NULL || cardData != NULL)
    {
        if(Compare > 0)
        {
            ret = EXPIRED_CARD ;
        }
        else
        {
            ret = TERMINAL_OK ;
        }
    }
    else
    {
        ret = EXPIRED_CARD ;
    }
    return ret ;
}

static EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t ret = TERMINAL_OK ;

    if(termData != NULL)
    {
        printf("Enter transaction amount : ");
        scanf("%f", &(termData->transAmount));
        if((termData->transAmount) <= 0)
        {
            ret = INVALID_AMOUNT ;
        }
        else
        {
            ret = TERMINAL_OK ;
        }
    }
    else
    {
        ret = INVALID_AMOUNT ;
    }
    return ret ;
}

static EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    EN_terminalError_t ret = TERMINAL_OK ;

    if(termData != NULL)
    {
        if( termData->maxTransAmount > Terminal_Max_Allowed_Amount )
        {
            ret = EXCEED_MAX_AMOUNT ;
        }
        else
        {
            ret = TERMINAL_OK ;
        }
    }
    else
    {
        ret = EXCEED_MAX_AMOUNT ;
    }
    return ret ;
}

static EN_terminalError_t setMaxAmount(ST_terminalData_t *termData, float maxAmount)
{
    EN_terminalError_t ret = TERMINAL_OK ;

    if(termData != NULL)
    {
        termData->maxTransAmount = maxAmount ;
        ret = TERMINAL_OK ;
    }
    else
    {
        ret = INVALID_MAX_AMOUNT ;
    }
    return ret ;
}

static EN_terminalError_t isValidCardPAN(ST_cardData_t *cardData)       // Optional
{
    EN_terminalError_t ret = TERMINAL_OK ;

    if(cardData != NULL)
    {
        if((PANLuhnCheck(cardData->primaryAccountNumber)) != 3)
        {
            ret = TERMINAL_OK ;
        }
        else
        {
            ret = INVALID_CARD ;
        }
    }
    else
    {
        ret = INVALID_CARD ;
    }
    return ret ;
}

