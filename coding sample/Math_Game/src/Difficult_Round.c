#include "Header.h"


void Diffcult_Round()
{
    srand(time(NULL));
    int ran_Num = 0;
    int Result = 0;
    int binary_Num[8] = {0,0,0,0,0,0,0,0,0};
    unsigned int point_result = 0;
    for(int x = 0; x < 5; x++)
    {
        ran_Num = (rand() % (MAX + 1 - MIN)) + MIN;     //Random number in range MIN-MAX
        printf("%d\n",ran_Num);                         //For debugging - showing the answer before user guessing
        Conver_To_Binary(&ran_Num, &binary_Num[0]);     //Converting decimal number to binary number and assign them into binary_Num array
        printf("Difficult mode...\n");
        printf("Question %d \n", x + 1);
        printf("What is decimal value of ");
        for(int i = 7; i >= 0; i--)
        {
            printf("%d", binary_Num[i]);                //Print the binary numbers
        }
        printf(": ");
        scanf("%d",&Result);

        if(Result == ran_Num)                           //Checking result by comparing the input value from user and random number which was generated
        {
            printf("Correct \n");
            point_result++;
        }
        else
        {
            printf("Your answer is wrong \n");
            printf("The answer is %d \n", ran_Num);
        }
        getch();
        printf("\n");
    }
    printf("Your point is: %d\n",point_result);
    getch();
    system("cls");                                      //Clean the screen after this game.

}

void Conver_To_Binary(const int* random_Num, int* result )     
{
    int Num = *random_Num;
    for(int i = 0; i < 7; i++)
    {
        if(Num != 0)
        {
            *result = (Num % 2 == 0) ? 0 : 1;               //Converting decimal to binary
            Num = Num  >> 1;                                //divided by 2
            result++;                                       //Point to next element in int array
        }
        else if(Num == 0)
        {
            *result = 0;
            result++;
        }
    }
}
