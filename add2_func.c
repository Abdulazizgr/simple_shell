#include "shell.h"
/**
 * _itoa - converts an integer to ASCII
 * @num: number
 * @bas: base
 * Reference: geeksforgeeks
 * Return: character string
 **/
char *_itoa(int num, int bas)
{
static char *dig = "0123456789abcdef";
static char buf[50];
char sig = 0;
char *ptr;
unsigned long n = (unsigned long)num;
if (num < 0)
{
n = (unsigned long)(-num);
sig = '-';
}
ptr = &buf[49];
*ptr = '\0';
do {
*--ptr = dig[n % bas];
n /= bas;
} while (n != 0);
if (sig)
*--ptr = sig;
return (ptr);
}
/**
 * str_len - returns the length of a string
 * str - short description
 * Description: long desc
 * @str: string to be measured
 * Return: length of string
 */
int _str(const char *str)
{
int length = 0;
while (str[length] != '\0')
{
length++;
}
return (length + 1);
}
