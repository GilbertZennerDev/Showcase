#include <unistd.h>

int main(int ac, char **av)
{
    if(ac < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    int i = 1;
    while(i < ac)
    {
        while(*av[i])
        {
            write(1, av[i], 1);
            av[i]++;
        }
        write(1, "\n", 1);
        i++;
    }
    return (0);
}