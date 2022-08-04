#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("wie ist dein Name?");
    printf("hello, %s\n", name);
}