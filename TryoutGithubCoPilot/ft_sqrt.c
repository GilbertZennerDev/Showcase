#include <stdio.h>
#include <time.h>

int ft_sqrt_binary(int nb)
{
    if (nb < 0)
        return 0;

    int low = 0;
    int high = nb;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (mid * mid == nb)
            return mid;
        else if (mid * mid < nb)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return 0;
}

int ft_sqrt_v(int nb)
{
    int i;

    i = 1;
    while (nb > 0)
    {
        nb -= i;
        i += 2;
    }
    if (nb == 0)
    {
        return (i / 2);
    }

    return (0);
}

int ft_sqrt_newton(int nb)
{
    if (nb < 0)
        return 0;

    int x = 1;

    while (x <= nb / x)
    {
        if (x == nb / x)
            return x;
        x++;
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    int i;
    clock_t start, end;
    double cpu_time_used;

    // Measure time for ft_sqrt_v
    start = clock();
    for (i = 0; i <= 1000000; i++)
    {
        ft_sqrt_v(i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by ft_sqrt_v: %f seconds\n", cpu_time_used);

    // Measure time for ft_sqrt_binary
    start = clock();
    for (i = 0; i <= 1000000; i++)
    {
        ft_sqrt_newton(i);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by ft_sqrt_binary: %f seconds\n", cpu_time_used);

    return 0;
}