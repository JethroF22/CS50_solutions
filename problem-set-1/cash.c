#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int coins[4] = {25, 10, 5, 1};
    int coins_index = 0;
    int coin = coins[coins_index];
    int num_coins = 0;
    int change_owed;
    do
    {
        change_owed = (int) round(get_float("Change owed: ") * 100);
    } while (change_owed < 0);

    eprintf("%d\n", change_owed);

    if (coin > change_owed)
    {
        do
        {
            coins_index++;
            coin = coins[coins_index];
        }
        while(coin > change_owed);
    }

    while(change_owed > 0)
    {
        change_owed -= coin;
        num_coins++;
        if (coin > change_owed)
        {
            coins_index++;
            coin = coins[coins_index];
        }
    }

    printf("%d\n", num_coins);
}