/**********************************************************************************
Inputting a text file full of integers and see them sorted from smallest to largest
This program shall generate new 20 random numbers to example.txt automatically
After that, the program shall read, sort and write to example.txt new order of those numbers
Date: 19/10/17
***********************************************************************************/

#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "header.h"

void Sorting(char file[], int strp[]);
void RandomNum(char file[]);


void SortingFile()
{
    char str1[20];
    int c = 0;
    int str[20];

    printf("Enter file txt name: ");
    scanf("%s", str1);

/**********************************************************
Random number to file example.txt
***********************************************************/
    RandomNum(str1);

/*************************************************************
Reading Input Text File and store its values to str array
**************************************************************/

    FILE *fp;
    fp = fopen(str1, "r");
    if(fp != NULL)
    {
        printf("Before sorting \n");
        while((fscanf(fp, "%d", &str[c])) != EOF)
        {
            printf("%d\n", str[c] );
            c++;
        }
        fclose(fp);
    }
    else
        printf("Error! While opening file");

/*********************************************************
Sorting
**********************************************************/

    Sorting(str1,str);

    printf("\n");
}

/**********************************************************
Random number to file example.txt
***********************************************************/
void RandomNum(char file[])
{
    int randNum;
    srand(time(NULL));
    FILE *fp;
    fp = fopen(file, "w");

    if(fp != NULL)
    {
        for(int i = 0; i <= 19; i++)
        {
            randNum = rand() % 100;
            fprintf(fp,"%d\n",randNum);
        }
        fclose(fp);
    }
    else
        printf("Error! While opening file");
}


/*********************************************************
Sorting from smallest by using Bubble Sort
**********************************************************/
void Sorting(char file[], int str[])
{
    int temp;
    int i,j;

    FILE *fp;
    fp = fopen(file, "w");

    if(fp != NULL)
    {
        printf("Sorting those numbers \n");
        for (i = 0 ; i < ( 20 - 1 ); i++)
        {
            for (j = 0 ; j < 20 - i - 1; j++)
            {
                if (str[j] > str[j+1]) /* For decreasing order use < */
                {
                    temp   = str[j];
                    str[j] = str[j+1];
                    str[j+1] = temp;
                }
            }
        }

        printf("Sorted list in ascending order:\n");


        for ( i = 0 ; i < 20 ; i++ )
        {
            printf("%d\n", str[i]);
            fprintf(fp,"%d\n",str[i]);
        }
        fclose(fp);
    }
    else
        printf("Error! While opening file");
}


