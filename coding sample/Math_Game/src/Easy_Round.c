#include "Header.h"


void Easy_Round()
{
    unsigned int point_result = 0;
    srand(time(NULL));
    Num num;
    num.Result = 0;

    char Math[2][1] = {"+","-"};
    int a = 0;
    for(int x = 0; x < 5; x++)
    {
        a = rand() % (sizeof(Math)/sizeof(Math[0]));                //Take random math operator from char Math[][]
        num.First_Num = (rand() % (MAX + 1 - MIN)) + MIN;           //Random number in range MIN-MAX
        num.Second_Num =  (rand() % (MAX + 1 - MIN)) + MIN;         //Random number in range MIN-MAX
        printf("Easy mode...\n");
        printf("Question %d \n", x + 1);
        printf("%d %c %d = ", num.First_Num, Math[a][0], num.Second_Num);
        scanf("%d",&num.Result);
        Checking_Result(num.First_Num, num.Second_Num, Math[a][0], &num.Result, &point_result);

        getch();
        printf("\n");
    }
    printf("Your point is: %u\n",point_result);
    getch();
    system("cls");                                                  //Clearing screen after finish this game
}

void Checking_Result(int A, int B, char Math, const int* result,unsigned int* point_result)             //Checking result by take the char from char Math - do Math
{                                                                                                       //Then compare the result which calculated by computer and giving answer from user
    if(Math == '+')                                                                                     //Using const int* result - to prevent unintended changing the giving answer from user
    {
        int result_Cal = A + B;

        if(result_Cal == *result)
        {
            printf("Correct \n");
            (*point_result)++;
        }
        else
        {
            printf("Your answer is wrong \n");
            printf("Answer is: %d\n", result_Cal);
        }
    }
    else if(Math == '-')
    {
        int result_Cal = A - B;
        if(result_Cal == *result)
        {
            printf("Correct \n");
            (*point_result)++;
        }
        else
        {
            printf("Your answer is wrong \n");
            printf("Answer is: %d\n", result_Cal);
        }
    }
    else if(Math == '*')
    {
        int result_Cal = A * B;

        if(result_Cal == *result)
        {
            printf("Correct \n");
            (*point_result)++;
        }
        else
        {
            printf("Your answer is wrong \n");
            printf("Answer is: %d\n", result_Cal);
        }
    }
    else if(Math == '/')
    {
        int result_Cal = A / B;
        if(result_Cal == *result)
        {
            printf("Correct \n");
            (*point_result)++;
        }
        else
        {
            printf("Your answer is wrong \n");
            printf("Answer is: %d\n", result_Cal);
        }
    }

}


