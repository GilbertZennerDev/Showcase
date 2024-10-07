#include <unistd.h>

void nl()
{
    write(1, "\n", 1);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        nl();
        return (0);
    }
    int i = 0;
    while(argv[1][i] == 32 || argv[1][i] == 9)
    {
        i++;
    }
    while(argv[1][i] != 32  && argv[1][i] != 9 && argv[1][i] != 0)
    {
        ft_putchar(argv[1][i]);
        i++;
    }
    nl();
    return (0);
}