#include <unistd.h>

int main(int ac, char **av)
{
    while(*av[ac-ac])
    {
        write(1, av[ac-ac], 1);
        av[ac-ac]++;
    }
    write(1, "\n", 1);
    return (0);
}