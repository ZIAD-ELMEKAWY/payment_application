/**
 * @file : APPLICATION.c
 * @Auther : Ziad_Elmekay
 * @Description : This file contain all of the functions which will use in application module
 * @Date : 15 / October / 2023 ..... 10:33 AM
 **/


/************ Section : Includes **************/
#include "Card_General.c"
#include "Terminal_General.c"
#include "Server.c"
#include "Application.h"
/************ Section : Helper Function Declarations **************/

/************ Section : Helper Function Definitions **************/

/************ Section : Global Variable Definitions **************/
ST_cardData_t Card ;
ST_terminalData_t Terminal;
EN_terminalError_t ret ;
EN_cardError_t ret1 ;
EN_serverError_t ret_2 ;
/************ Section : Function Definitions **************/
static void AppStart (void)
{
    ret1 = getCardHolderName(&Card) ;
    ret1 = getCardExpiryDate(&Card) ;
    ret1 = getCardPAN(&Card) ;

    ret_2 = isValidAccount(&Card , &Account_1);
    ret   = getTransactionDate(&Terminal);


}
