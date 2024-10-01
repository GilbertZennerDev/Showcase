int ft_iterative_factorial(int nb)
{
    int i = 1;
    if(nb < 0)
        return (0);
    if(!nb)
        return (1);
    while(nb > 1)
        i *= nb--;
    return (i);
}