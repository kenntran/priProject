/************************************************************************
Testing program - used for unit test - testing functions
Main program to call children functions from .cpp files
Date: 19/10/17
*************************************************************************/

#include "header.h"
#include "PocketCalculator.cpp"
#include "CheckingNumber.cpp"
#include "CovertingDegree.cpp"
#include "ConvertingToBinary.cpp"
#include "SortingFile.cpp"

struct Calculator
{
    int x1, x2;
    char oper;
};
int testingResult;
//int inputNumber;
//float Celsius;
//int InputIntegeNumber;

int main()
{
    while(1)
    {
        struct Calculator cal;
        cal.x1 = 3;
        cal.x2 = 3;
        cal.oper = '+';

        int chosen;
        printf("Choose which function would like to test\n");
        printf("1. PocketCalculator function \n");
        printf("2. CheckingNumber function \n");
        printf("3. ConvertingDegree function \n");
        printf("4. ConvertingToBinary function \n");
        printf("5. SortingFile function \n");
        printf("Please enter function's number you want: \n");
        scanf("%d",&chosen);

         switch(chosen)
        {
            case 1:                             //Choose random number and operator to test function
                testingResult = PocketCalculator(cal.x1, cal.x2, cal.oper);
                if(testingResult == 6)
                {
                    printf("Correct\n");
                }
                else
                    printf("False\n");

                printf("\n");
                break;

            case 2:                             // In this case, checking result by observe the result on screen
                CheckingNumber(7);              // Checking result of number 7 - if function print all (odd) number from 1 to 7 - correct, else incorrect
                break;

            case 3:                             // In this case, checking result by observe the result on screen
                ConvertingDegree(30);           // Checking function with random temperature - in this case (30) => K = 30 + 273.15, F = (30 * 1.8) +32
                printf("\n");
                break;

            case 4:                             // In this case, checking result by observe the result on screen - Input integer number must be < 256
                ConvertingToBinary(15);         // It should be 00001111
                printf("\n");
                break;

            case 5:                             // In this case, checking result by observe the result on screen
                SortingFile();                  // It will generate automatically random numbers to file example.txt - Then, read and sort it from smallest
                printf("\n");
                break;

            default:
                printf("You have not chosen any function yet\n");
                printf("\n");
                break;
        }
    }

    return 0;
}
