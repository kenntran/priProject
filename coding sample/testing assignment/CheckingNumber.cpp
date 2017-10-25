/****************************************************************
if numbers are odd or even from 1 to given number
*****************************************************************/

#include "stdio.h"
#include "header.h"

void CheckingNumber(int inputNumber)
{

    if((inputNumber % 2) == 0)
    {
        printf("Even numbers from 1 to your number %d are: \n", inputNumber);
        for(int i = 1; i <= inputNumber / 2; i++)
        {
            printf("%d", 2 * i );

        }

    }
    else
    {
        printf("Odd numbers from 1 to your number %d are: \n", inputNumber);
        for(int i = 1; i <= inputNumber; i++)
        {
            if( i % 2 == 1)
            {
                printf("%d", i );
            }
        }
    }
    printf("\n");
}
