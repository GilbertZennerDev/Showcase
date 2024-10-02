#include <unistd.h>

int ft_str_is_alpha(char *str)
{
    while(*str)
        if(!((*str >= 'a' && *str <= 'z')||(*str >= 'A' && *str <= 'Z')))
            return (0);
    return (1);
}