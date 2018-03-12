#include "Header.h"

void Normal_Round()
{
    unsigned int point_result = 0;
    srand(time(NULL));
    Num num_Nor;
    num_Nor.Result = 0;

    char Math[2][1] = {"*","/"};
    int a = 0;
    for(int x = 0; x < 5; x++)
    {
        a = rand() % (sizeof(Math)/sizeof(Math[0]));                                //Take random math operator from char Math[][]
        num_Nor.First_Num = (rand() % (MAX + 1 - MIN)) + MIN;                       //Random number in range MIN-MAX
        num_Nor.Second_Num =  (rand() % (MAX + 1 - MIN)) + MIN;                     //Random number in range MIN-MAX
        printf("Difficult mode...\n");
        printf("Question %d \n", x + 1);
        printf("%d %c %d = ? \n", num_Nor.First_Num,Math[a][0], num_Nor.Second_Num);
        printf("With the floating result - you only need answer integer number\n");
        scanf("%d",&num_Nor.Result);
        Checking_Result(num_Nor.First_Num, num_Nor.Second_Num, Math[a][0], &num_Nor.Result, &point_result);     //Calling the Checking_Result function from Easy_Round

        getch();
        printf("\n");
    }
    printf("Your point is: %d\n",point_result);
    getch();
    system("cls");                                                                  //Clearing screen after finish this game
}



