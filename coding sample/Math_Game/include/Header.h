#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

#define MIN 1
#define MAX 100

typedef struct Numbers
{
    int First_Num;
    int Second_Num;
    int Result;

} Num;

void Easy_Round();
void Normal_Round();
void Diffcult_Round();

void Checking_Result(int A, int B, char Math, const int* result, unsigned int* point_result);
void Conver_To_Binary(const int* ran_Num, int* result );


#endif // HEADER_H

