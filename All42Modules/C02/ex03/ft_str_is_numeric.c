#include <unistd.h>

int ft_str_is_numeric(char *str)
{
    while(*str)
        if(!(*str >= '0' && *str <= '9'))
            return (0);
    return (1);
}