#include <unistd.h>

int ft_str_is_lower_alpha(char *str)
{
    while(*str)
        if(!(*str >= 'a' && *str <= 'z'))
            return (0);
    return (1);
}