/****************************************************************
Converting temperature degrees Celsius converted to Kelvin and Fahrenheit
*****************************************************************/

#include "stdio.h"
#include "header.h"

void ConvertingDegree(float Celsius)
{

    printf("%0.1f in Celsius will be: %0.2f in Kevin\n", Celsius, Celsius + 273.15);
    printf("%0.1f in Celsius will be: %0.2f in Fah\n", Celsius, (Celsius * 1.8) + 32);

    printf("\n");

}
