#include <unistd.h>

int ft_sqrt(int nb)
{
    int i;
    if(nb <= 0)
        return (0);
    else if(nb == 1)
        return (1);
    i = 1;
    while (i <= nb / i)
        {
            if(i == nb / i)
                return (i);
            i++;
        }
    return (0);
}