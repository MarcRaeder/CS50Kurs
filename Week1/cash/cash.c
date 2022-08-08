#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int pennies = 0;

int main(void)
{
    int cents = get_cents();

    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;
    pennies = cents;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i\n", coins);
}

int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("Enter Cents Owed: ");
    } while (cents < 0);

    return cents;
}

int calculate_quarters(int cents)
{
    int quarters = 0;
    quarters = cents / 25;
    
    return quarters;
}

int calculate_dimes(int cents)
{
    int dimes = 0;
    dimes = cents / 10;

    return dimes;
}

int calculate_nickels(int cents)
{
    int nickels = 0;
    nickels = cents / 5;
    
    return nickels;
}
