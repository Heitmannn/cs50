#include <cs50.h>
#include <stdio.h>

int print_repetitions(char *a, int i)
{
    for (int j = 0; j < i; j++)
    {
        printf("%s", a);
    }
    return 0;
}

int main(void)
{
    int n = 0;
    while (n < 1 || n > 8)
    {
        n = get_int("Number # ");
    }

    for (int i = 1; i <= n; i++)
    {
        print_repetitions(" ", n - i);
        print_repetitions("#", i);
        printf("  ");
        print_repetitions("#", i);
        printf("\n");
    }
    return 0;
}

