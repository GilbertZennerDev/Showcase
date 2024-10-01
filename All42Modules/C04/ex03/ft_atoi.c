#include <unistd.h>

int ft_atoi(char *str)
{
    int decimal;
    int result;
    int sign;
    
    sign = 1;
    decimal = 0;
    while(*str == ' ' || *str == '\t')
        str++;
    if(*str == '-')
        sign = -1;
    while(*str == '-' || *str == '+')
        str++;
    while(*str >= '0' && *str <= '9' && *str != '\0')
    {
        decimal = decimal * 10 + (*str - '0');
        str++;
    }
    result = sign * decimal;
    return (result);
}