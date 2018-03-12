#ifndef EASY_ROUND_H
#define EASY_ROUND_H

#include <time.h>
#include <stdlib.h>
#include <conio.h>



typedef struct Numbers
{
    int First_Num;
    int Second_Num;
    int Result;

} Num;

void Easy_Round();

void Checking_Result_Easy(int A, int B, char Math, int result);

int Random_Number();



#endif // EASY_ROUND_H
