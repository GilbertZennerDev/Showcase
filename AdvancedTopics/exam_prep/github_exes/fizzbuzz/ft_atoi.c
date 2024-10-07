/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str);
*/

#include <stdio.h>

int	ft_atoi(const char *str)
{
	int result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
    {
        str++;
    }
    if(*str == '-')
        sign = -1;
    if(*str == '-' || *str == '+')
    {
        str++;
    }
    while(*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return (result * sign);
}

int main(void)
{
    printf("500 : %d\n", ft_atoi("500"));
    printf("-500 : %d\n", ft_atoi("-500"));
    printf("+500 : %d\n", ft_atoi("+500"));
    return (0);
}