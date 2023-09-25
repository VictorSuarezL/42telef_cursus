// Compila con: gcc main.c -L/Users/victorsanz/Documents/42telef_cursus/libft -lft && ./a.out
#include "libft.h"
#include <stdio.h>
#include <libc.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

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

    // Test 5 - isprint(0) == ft_isprint(0)
    i = 0;
    while (i < 256)
    {
        if (isprint(i) != ft_isprint(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }

    printf("ft_isprint: OK\n");

    // Test 6 - strlen("Hello") == ft_strlen("Hello")
    char *str = "Hello";
    if (strlen(str) != ft_strlen(str))
    {
        printf("Error at ft_strlen");
        return (1);
    }

    printf("ft_strlen: OK\n");

    // Test 7 - memset("Hello", 'a', 3) == ft_memset("Hello", 'a', 3)
    char str1[10];
    char str2[10];

    memset(str1, 0, sizeof(str1));
    memset(str2, 0, sizeof(str2));

    memset(str1, 'a', 3);
    ft_memset(str2, 'a', 3);
    if (strcmp(str1, str2) != 0)
    {
        printf("Error at ft_memset: str1 = %s, str2 = %s\n", str1, str2);
        return (1);
    }

    printf("ft_memset: OK\n");

    // Test 8 - bzero("Hello", 3) == ft_bzero("Hello", 3)
    char str3[100];
    char str4[100];

    // memset(str3, 0, sizeof(str3));
    // memset(str4, 0, sizeof(str4));

    if (strcmp(bzero(str3, sizeof(str3)), ft_bzero(str4, sizeof(str4))) != 0)
    {
        printf("Error at ft_bzero: str3 = %s, str4 = %s\n", str3, str4);
        return (1);
    }

    printf("ft_bzero: OK\n");

    // Test 9 - memcpy("Hello", "World", 3) == ft_memcpy("Hello", "World", 3)
    char str5[5];
    char str6[5];

    memset(str5, 0, sizeof(str5));
    memset(str6, 0, sizeof(str6));

    memcpy(str5, "Hello", 3);
    ft_memcpy(str6, "Hello", 3);
    if (strcmp(str5, str6) != 0)
    {
        printf("Error at ft_memcpy: str5 = %s, str6 = %s\n", str5, str6);
        return (1);
    }

    // printf("Test memcpy: \n\tft_memcopy: %s\n\tmemcpy: %s\n",
    //     ft_memcpy("  ", 0, 2), memcpy("  ", 0, 2));

    printf("ft_memcpy: OK\n");

    // Test 10 - memmove("Hello", "World", 3) == ft_memmove("Hello", "World", 3)
    char str7[14] = "Hello, world!";
    char str8[13];
    char str81[13];
    char str9[20];
    char str91[20];

    // printf("str7 = %s\n", str7);

    memset(str8, 0, sizeof(str8));
    memset(str9, 0, sizeof(str9));
    memset(str81, 0, sizeof(str81));
    memset(str91, 0, sizeof(str91));


    // printf("dest < src\n");
    // printf("\tsize_of dest (str8) = %lu\n", sizeof(str8));
    // printf("\tsize_of src (str7) = %lu\n", sizeof(str7));

    ft_memmove(str8, str7, 13);
    memmove(str81, str7, 13);
    // printf("\tstr8 = %s <--> str81 = %s\n", str8, str81);

    // if (strcmp(str8, str81) != 0)
    // {
    //     printf("Error at ft_memmove:\nft_str8 = '%s', \nstr81 = '%s'\n", str8, str81);
    //     return (1);
    // }

    // printf("dest > src\n");
    // printf("\tsize_of dest (str9) = %lu\n", sizeof(str9));
    // printf("\tsize_of src (str7) = %lu\n", sizeof(str7));

    ft_memmove(str9, str7, 13);
    memmove(str91, str7, 13);
    // printf("str9 = %s <--> str91 = %s\n", str9, str91);

    if (strcmp(str9, str91) != 0)
    {
        printf("Error at ft_memmove: str9 = %s, str91 = %s\n", str9, str91);
        return (1);
    }

    printf("ft_memmove: OK\n");

    // Test 11 - strlcpy("Hello", "World", 3) == ft_strlcpy("Hello", "World", 3)
    char str10[5];
    char str11[5];

    memset(str10, 0, sizeof(str10));
    memset(str11, 0, sizeof(str11));

    strlcpy(str10, "Hello", 3);
    ft_strlcpy(str11, "Hello", 3);

    // if (strcmp(str10, str11) != 0)
    // {
    //     printf("Error at ft_strlcpy: str10 = %s, str11 = %s\n", str10, str11);
    //     return (1);
    // }

    printf("ft_strlcpy: OK\n");

    // Test 12 - strlcat("Hello", "World", 3) == ft_strlcat("Hello", "World", 3)
    char str12[10];
    char str13[10];

    memset(str12, 0, sizeof(str12));
    memset(str13, 0, sizeof(str13));

    // printf("Test size = 0\n");
    strlcat(str12, "Hello", 0);
    ft_strlcat(str13, "Hello", 0);

    // printf("\tstr12 = %s\n", str12);
    // printf("\tstr13 = %s\n", str13);

    if (strcmp(str12, str13) != 0)
    {
        printf("Error at ft_strlcat: str12 = %s, str13 = %s\n", str12, str13);
        return (1);
    }

    // printf("Test size < dest_len\n");
    char str14[10] = "Hello, ";
    char str15[10] = "Hello, ";

    strlcat(str14, "world!", 6);
    ft_strlcat(str15, "world!", 6);

    // printf("\tstr14 = %s\n", str14);
    // printf("\tstr15 = %s\n", str15);

    if (strcmp(str14, str15) != 0)
    {
        printf("Error at ft_strlcat: str14 = %s, str15 = %s\n", str14, str15);
        return (1);
    }

    // printf("Test size > dest_len\n");
    char str16[10] = "Hello, ";
    char str17[10] = "Hello, ";

    strlcat(str16, "world!!!!!", 10);
    ft_strlcat(str17, "world!!!!!", 10);

    // printf("\tstr16 = %s\n", str16);
    // printf("\tstr17 = %s\n", str17);

    if (strcmp(str16, str17) != 0)
    {
        printf("Error at ft_strlcat: str16 = %s, str17 = %s\n", str16, str17);
        return (1);
    }

    printf("ft_strlcat: OK\n");

    // Test 13 - toupper('a') == ft_toupper('a')

    i = 0;
    while (i < 256)
    {
        if (toupper(i) != ft_toupper(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }

    printf("ft_toupper: OK\n");

    // Test 14 - tolower('A') == ft_tolower('A')

    i = 0;
    while (i < 256)
    {
        if (tolower(i) != ft_tolower(i))
        {
            printf("Error at %d\n", i);
            return (1);
        }
        i++;
    }

    printf("ft_tolower: OK\n");

    // Test 15 - strchr("Hello", 'l') == ft_strchr("Hello", 'l')

    char *str18 = "Hello";
    char *d01 = strchr(str18, 'l');
    char *d02 = ft_strchr(str18, 'l');

    if (strchr(str18, 'l') != ft_strchr(str18, 'l'))
    {
        printf("Error at ft_strchr: d01 = %s, d02 = %s\n", d01, d02);
        return (1);
    }

    char *str19 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
    char *d1 = strchr(str19, '\0');
    char *d2 = ft_strchr(str19, '\0');

    if (d1 != d2)
    {
        printf("Error at ft_strchr: d1 = %s, d2 = %s\n", d1, d2);
        return (1);
    }



    // printf("strchr('teste', 'e' + 256): %s\n", strchr("teste", 'e' + 256));
    // printf("ft_strchr('teste', 'e' + 256): %s\n", ft_strchr("teste", 'e' + 256));
    // printf("strchr('teste', 1024): %i\n", strchr("teste", 1024));
    // printf("ft_strchr('teste', 1024): %i\n", ft_strchr("teste", 1024));

    printf("ft_strchr: OK\n");

    // Test 16 - strrchr("Hello", 'l') == ft_strrchr("Hello", 'l')

    char *str20 = "Hello";
    char *d3 = strrchr(str20, 'l');
    char *d4 = ft_strrchr(str20, 'l');

    if (d3 != d4)
    {
        printf("Error at ft_strrchr: d3 = %s, d4 = %s\n", d3, d4);
        return (1);
    }

    char *d5 = strrchr(str19, '\0');
    char *d6 = ft_strrchr(str19, '\0');

    if (d5 != d6)
    {
        printf("Error at ft_strrchr: d5 = %s, d6 = %s\n", d5, d6);
        return (1);
    }

    printf("ft_strrchr: OK\n");

    // Test 17 - strncmp("Hello", "World", 3) == ft_strncmp("Hello", "World", 3)

    char *str21 = (char *)"xxxxxx";
    char *str22 = (char *)"yyyyyy";

    if (strncmp(str21, str22, 0) != ft_strncmp(str21, str22, 0))
    {
        printf("Error at ft_strncmp: str21 = %s, str22 = %s\n", str21, str22);
        return (1);
    }

    if (strncmp(str21, str22, 3) != ft_strncmp(str21, str22, 3))
    {
        printf("Error at ft_strncmp: str21 = %s, str22 = %s\n", str21, str22);
        return (1);
    }

	// printf("std: %i, yours: %i\n", strncmp(str21, str22, 20), ft_strncmp(str21, str22, 20));
	// printf("std: %i, yours: %i\n", strncmp(str21, str22, 0), ft_strncmp(str21, str22, 0));
	// printf("std: %i, yours: %i\n", strncmp(str21, str22, 1), ft_strncmp(str21, str22, 1));

	char *str23 = "abcadef";
	char *str24 = "abcad";

    if (strncmp(str23, str24, 0) != ft_strncmp(str23, str24, 0))
    {
        printf("Error at ft_strncmp: str23 = %s, str24 = %s\n", str23, str24);
        return (1);
    }

    if (strncmp(str23, str24, 5) != ft_strncmp(str23, str24, 5))
    {
        printf("Error at ft_strncmp: str23 = %s, str24 = %s\n", str23, str24);
        return (1);
    }

    if (strncmp(str23, str24, 6) != ft_strncmp(str23, str24, 6))
    {
        printf("Error at ft_strncmp: str23 = %s, str24 = %s\n", str23, str24);
        return (1);
    }

	// printf("std: %i, yours: %i\n", strncmp(str23, str24, 5), ft_strncmp(str23, str24, 5));
	// printf("std: %i, yours: %i\n", strncmp(str23, str24, 6), ft_strncmp(str23, str24, 6));

	char *str25 = "abcad";
	char *str26 = "abcadtg";

        if (strncmp(str25, str26, 0) != ft_strncmp(str25, str26, 0))
    {
        printf("Error at ft_strncmp: str25 = %s, str26 = %s\n", str25, str26);
        return (1);
    }

    if (strncmp(str25, str26, 5) != ft_strncmp(str25, str26, 5))
    {
        printf("Error at ft_strncmp: str25 = %s, str26 = %s\n", str25, str26);
        return (1);
    }

    if (strncmp(str25, str26, 6) != ft_strncmp(str25, str26, 6))
    {
        printf("Error at ft_strncmp: str25 = %s, str26 = %s\n", str25, str26);
        return (1);
    }
	// printf("std: %i, yours: %i\n", strncmp(str25, str26, 5), ft_strncmp(str25, str26, 5));
	// printf("std: %i, yours: %i\n", strncmp(str25, str26, 6), ft_strncmp(str25, str26, 6));

    char *str27 = "\200";
	char *str28 = "\0";

    if (strncmp(str27, str28, 1) != ft_strncmp(str27, str28, 1))
    {
        printf("Error at ft_strncmp: str27 = %s, str28 = %s\n", str27, str28);
        return (1);
    }

    // printf("std: %i, yours: %i\n", strncmp(str27, str28, 1), ft_strncmp(str27, str28, 1));

    char *s29 = "\x12\xff\x65\x12\xbd\xde\xad";
	char *s30 = "\x12\x02";

    if (strncmp(s29, s30, 6) != ft_strncmp(s29, s30, 6))
    {
        printf("Error at ft_strncmp: s29 = %s, s30 = %s\n", s29, s30);
        return (1);
    }

    // printf("std: %i, yours: %i\n", strncmp(s29, s30, 6), ft_strncmp(s29, s30, 6));

    printf("ft_strncmp: OK\n");

    // Test 18 - memchr("Hello", 'l', 3) == ft_memchr("Hello", 'l', 3)

    char *str31 = "Hello";
    char *d7 = memchr(str31, 'l', 3);
    char *d8 = ft_memchr(str31, 'l', 3);

    if (d7 != d8)
    {
        printf("Error at ft_memchr: d7 = %s, d8 = %s\n", d7, d8);
        return (1);
    }

    char *str32 = "Hello";
    char *d9 = memchr(str32, 'l', 0);
    char *d10 = ft_memchr(str32, 'l', 0);

    if (d9 != d10)
    {
        printf("Error at ft_memchr: d9 = %s, d10 = %s\n", d9, d10);
        return (1);
    }

    char *str33 = "Hello, world!";
    char *d11 = memchr(str33, 'd', 13);
    char *d12 = ft_memchr(str33, 'd', 13);

    // printf("d11 = %s, d12 = %s\n", d11, d12);

    if (d11 != d12)
    {
        printf("Error at ft_memchr: d11 = %s, d12 = %s\n", d11, d12);
        return (1);
    }

    printf("ft_memchr: OK\n");

    // Test memcmp

    char buffer1[] = "Hello, world!";
    char buffer2[] = "Hello, world!";
    char buffer3[] = "Hello, everyone!";

    // printf("1: memcmp = '%i'\t ft_memcmp: '%i'\n",
    //     memcmp(buffer1, buffer2, sizeof(buffer1)), ft_memcmp(buffer1, buffer2, sizeof(buffer1)));

    if (memcmp(buffer1, buffer2, sizeof(buffer1)) != ft_memcmp(buffer1, buffer2, sizeof(buffer1)))
    {
        printf("Error at ft_memcmp (1)\n");
        return (1);
    }

    // printf("1: memcmp = '%i'\t ft_memcmp: '%i'\n",
    //     memcmp(buffer1, buffer3, sizeof(buffer1)), ft_memcmp(buffer1, buffer3, sizeof(buffer1)));

    if (memcmp(buffer1, buffer3, sizeof(buffer1)) != ft_memcmp(buffer1, buffer3, sizeof(buffer1)))
    {
        printf("Error at ft_memcmp (1)\n");
        return (1);
    }

    // Test 19 - strnstr("Hello", "World", 3) == ft_strnstr("Hello", "World", 3)

    // printf("1: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(str33, "world", 13), ft_strnstr(str33, "world", 13));

    if (strnstr(str33, "world", 13) != ft_strnstr(str33, "world", 13))
    {
        printf("Error at ft_strnstr %s\n", str33);
        return (1);
    }

    // printf("2: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(str33, "world", 9), ft_strnstr(str33, "world", 9));

    if (strnstr(str33, "world", 9) != ft_strnstr(str33, "world", 9))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("3: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(str33, "world", -1), ft_strnstr(str33, "world", -1));

    if (strnstr(str33, "world", -1) != ft_strnstr(str33, "world", -1))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("4: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr("Hello, world but not this world!", "world", 11), ft_strnstr("Hello, world but not this world!", "world", 11));

    if (strnstr("Hello, world but not this world!", "world", 11) != ft_strnstr("Hello, world but not this world!", "world", 11))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    char haystack[30] = "aaabcabcd";
    char needle[10] = "aabc";

    // printf("a: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(haystack, needle, -1), ft_strnstr(haystack, needle, -1));

    if (strnstr(haystack, needle, -1) != ft_strnstr(haystack, needle, -1))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("b: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(haystack, "abcd", 9), ft_strnstr(haystack, "abcd", 9));

    if (strnstr(haystack, "abcd", 9) != ft_strnstr(haystack, "abcd", 9))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("c: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr(haystack, "cd", 8), ft_strnstr(haystack, "cd", 8));

    if (strnstr(haystack, "cd", 8) != ft_strnstr(haystack, "cd", 8))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("d: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr("lorem ipsum dolor sit amet", "ipsumm", 30), ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));

    if (strnstr("lorem ipsum dolor sit amet", "ipsumm", 30) != ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    // printf("d: strnstr: '%s'\t yours: '%s'\n",
    //     strnstr("lorem ipsum dolor sit amet", "ipsumm", 30), ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30));

    if (strnstr("lorem ipsum dolor sit amet", "ipsumm", 30) != ft_strnstr("lorem ipsum dolor sit amet", "ipsumm", 30))
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }
    char *s1 = "MZIRIBMZIRIBMZE123";
    char *s2 = "MZIRIBMZE";
    size_t max = strlen(s2);
    char *i1 = strnstr(s1, s2, max);
    char *i2 = ft_strnstr(s1, s2, max);

    // printf("e: strnstr: '%s'\t yours: '%s'\n", i1, i2);
    if (i1 != i2)
    {
        printf("Error at ft_strnstr\n");
        return (1);
    }

    printf("ft_strnstr: OK\n");

    // Test atoi

    // printf("%d\n", ft_atoi("  \n -1234567890"));
    // printf("%d\n", atoi("  \n -1234567890"));

    // Test calloc









    return (0);
}

