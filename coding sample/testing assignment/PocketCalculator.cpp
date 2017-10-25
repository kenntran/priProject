/*******************************************
This file include PocketCalculator function
Date: 19/10/17

*********************************************/

#include "stdio.h"
#include "header.h"

int PocketCalculator(int x1, int x2, char oper)
{
    int result;
    if(x1 != 0 && x2 !=0 && oper != 0)
    {
    	switch(oper)
    	    {
    	        case '+':
    	            result = x1 + x2;
    	            printf("The result of %d %c %d is: %d \n", x1, oper, x2, result);
    	            break;
    	        case '-':
    	            result = x1 - x2;
    	            printf("The result of %d %c %d is: %d \n", x1, oper, x2, result);
    	            break;
    	        case '*':
    	            result = x1 * x2;
    	            printf("The result of %d %c %d is: %d \n", x1, oper, x2, result);
    	            break;
    	        case '/':
    	            result = x1 / x2;
    	            printf("The result of %d %c %d is: %d \n", x1, oper, x2, result);
    	            break;
    	        default:
    	            printf("Your operator is not valid \n");
    	            break;
    	    }
    }
    else
    	printf("You did not enter enough value or operator to calculate \n");

    printf("\n");

    return result;
}
