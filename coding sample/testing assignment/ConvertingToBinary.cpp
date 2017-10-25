/*************************************************************************
Input an integer and see it in binary form
**************************************************************************/
#include "stdio.h"
#include "header.h"

void ConvertingToBinary(int InputIntegeNumber)
{
    int InputNumber = InputIntegeNumber, bufferNum;
    int str[7];
    printf("%d in binary number system is:\n", InputNumber);
    bufferNum = InputNumber;

    for(int i = 0; i < 8; i++)
    {
        if(bufferNum % 2 == 0)
        {
            str[i] = 0;
        }
        else
        {
            str[i] = 1;
        }
        bufferNum /= 2;
    }

    for (int h = 7; h >= 0; h--)
    {
        printf("%d",str[h]);
    }
    printf("\n");

}

