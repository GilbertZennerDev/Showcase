#include <unistd.h>

int ft_str_is_printable(char *str)
{
    while(*str)
        if(!(*str >= ' ' && *str <= '~'))
            return (0);
    return (1);
}