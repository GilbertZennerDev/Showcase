#include <unistd.h>

int ft_str_is_upper_alpha(char *str)
{
    while(*str)
        if(!(*str >= 'A' && *str <= 'Z'))
            return (0);
    return (1);
}