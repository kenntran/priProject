#include "Header.h"

int main()
{
    unsigned int Selected_Level = 0;

    do
    {
        printf("Welcome to Math Game \n");
        printf("Choosing level: \n");
        printf("1. Easy \n");
        printf("2. Normal \n");
        printf("3. Difficult \n");
        printf("4. Exit \n\n");
        scanf("%d",&Selected_Level);
        printf("qStarting game...\n");

        switch(Selected_Level)
        {
            case 1:
                printf("Easy Round starting...\n\n");
                getch();
                Easy_Round();
                break;
            case 2:
                printf("Normal Round starting... \n\n");
                getch();
                Normal_Round();
                break;
            case 3:
                printf("Difficult Round starting... \n\n");
                getch();
                Diffcult_Round();
                break;
        }
    }while(Selected_Level < 4);
}



