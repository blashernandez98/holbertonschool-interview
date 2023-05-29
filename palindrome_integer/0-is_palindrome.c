#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - checks if a given unsigned integer is a palindrome
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */

int is_palindrome(unsigned long n)
{
    int digits[21] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i = 20, j = 20;

    for (; i >= 0; i--)
    {
        if (n == 0)
            break;
        digits[i] = n % 10;
        n /= 10;
    }

    for (i = i + 1; i < j; i++, j--)
    {
        if (digits[i] != digits[j])
            return (0);
    }

    return (1);
}