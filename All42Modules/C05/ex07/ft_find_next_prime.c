#include <unistd.h>
#include <stdio.h>

int ft_is_prime(int nb);
int ft_find_next_prime(int nb);

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

int ft_find_next_prime(int nb)
{
    if(nb < 2)
        return (2);
    while(!ft_is_prime(nb))
    {
        nb++;
    }
    return (nb);
}