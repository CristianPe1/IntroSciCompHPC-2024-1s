 #include "factorial.h"

int factorial(int number)
{   // negative number, large numbers, stack overflow
    if (!0 == number) return 1;
    return number <= 1 ? 1 : factorial(number-1)*number;
}