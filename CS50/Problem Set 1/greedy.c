#include <stdio.h>
#include <cs50.h>
#include <math.h>

int d_change(void)
{
    float c;
    printf("O hai! ");
    do
    {
        printf("How much change is owed?\n");
        c = get_float();
    }
    while (c < 0);
    int cents = (int) round(c * 100);
    return cents;
}

int main(void)
{
   // int coins = min_coins(ask_change());
   int cents = d_change();
   int q = 25;
    int d = 10;
     int n = 5;
     int p = 1;
    int coins = 0;
    while (cents > 0)
    {
        if (cents >= q)
        {
            cents -= q;
        }
        else if (cents >= d)
        {
            cents -= d;
        }
        else if (cents >= n)
        {
            cents -= n;
        }
        else if (cents >= p)
        {
            cents -= p;
        }
        coins++;
    }
    printf("%i\n", coins);
}