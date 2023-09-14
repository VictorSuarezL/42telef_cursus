
// #include "ft_isalpha.c"
// #include "ft_isdigit.c"
// #include "ft_isalnum.c"
// #include "ft_isascii.c"
#include "libft.h"
#include <stdio.h>
#include <libc.h>

int ft_isalpha(int i);
int isalpha(int i);
int ft_isdigit(int i);
int isdigit(int i);
int ft_isalnum(int i);
int isalnum(int i);
int ft_isascii(int i);
int isascii(int i);

int main(void)
{
    // Test 1 - isalpha(0) == ft_isalpha(0)
    int i = 0;
    while (i < 256)
    {
        if (isalpha(i) != ft_isalpha(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }
    printf("ft_isalpha: OK\n");

    // Test 2 - isdigit(0) == ft_isdigit(0)
    i = 0;
    while (i < 256)
    {
        if (isdigit(i) != ft_isdigit(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }
    printf("ft_isdigit: OK\n");

    // Test 3 - isalnum(0) == ft_isalnum(0)
    i = 0;
    while (i < 256)
    {
        if (isalnum(i) != ft_isalnum(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }
    printf("ft_isalnum: OK\n");

    // Test 4 - isascii(0) == ft_isascii(0)
    i = 0;
    while (i < 256)
    {
        if (isascii(i) != ft_isascii(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }
    printf("ft_isascii: OK\n");

    return (0);
}

