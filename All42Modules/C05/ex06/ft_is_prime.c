#include <unistd.h>

int ft_is_prime(int nb)
{
    if(nb <= 1)
        return (0);
    if(nb <= 3)
        return (1);
    if(!(nb%2)||!(nb%3))
        return (0);
    int i = 5;
    while(i <= nb / i)
    {
        if(!(nb % i))
            return (0);
        i += 2;
    }
    return (1);
}