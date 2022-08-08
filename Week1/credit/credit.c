#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long creditcardnumber = get_long("Creditcardnumber: ");

    int numberofdigits = 0;
    long usedcreditcardnumber = creditcardnumber;
    while (usedcreditcardnumber > 0)
    {
        usedcreditcardnumber = usedcreditcardnumber / 10;
        numberofdigits++;
    }

    if (numberofdigits != 13 && numberofdigits != 15 && numberofdigits != 16)
    {
        printf("INVALID\n");

        return 0;
    }

    int sum1 = 0;
    int sum2 = 0;
    long ccn = creditcardnumber;
    int total = 0;
    int modulofirstdigit;
    int moduloseconddigit;
    int digit1;
    int digit2;
    
    do
    {

        modulofirstdigit = ccn % 10;
        ccn = ccn / 10;
        sum1 = sum1 + modulofirstdigit;

        moduloseconddigit = ccn % 10;
        ccn = ccn / 10;

        moduloseconddigit = moduloseconddigit * 2;
        digit1 = moduloseconddigit % 10;
        digit2 = moduloseconddigit / 10;
        sum2 = sum2 + digit1 + digit2;

    } while (ccn > 0);

    total = sum1 + sum2;

    if (total % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    long start = creditcardnumber;
    do
    {
        start = start / 10;
    } while (start > 100);

    bool numberFitsMASTERCARDCriteria = start / 10 == 5 && 0 < start % 10 && start % 10 < 6;
    bool numberFitsAMEXCriteria = start / 10 == 3 && start % 10 == 4 || start % 10 == 7;
    bool numberFitsVISACriteria = start / 10 == 4;

    if (numberFitsMASTERCARDCriteria)
    {
        printf("MASTERCARD\n");
    }
    else if (numberFitsAMEXCriteria)
    {
        printf("AMEX\n");
    }
    else if (numberFitsVISACriteria)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
