#include <unistd.h>

void nl()
{
    write(1, "\n", 1);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr(char *s)
{
    while(*s)
    {
        ft_putchar(*s);
        s++;
    }
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        nl();
        return (0);
    }
    while(*argv[1] == 32 || *argv[1] == 9)
        argv[1]++;
    while (*argv[1] != 32 && *argv[1] != 9 && *argv[1] != 0)
    {
        ft_putchar(*argv[1]);
        argv[1]++;
    }
    nl();
    return (0);
}