//job is to write a program which displays all chars of a string, but with 3 spaces between each char except after the last char
// if there are more than 1 argv, display \n

#include <unistd.h>

void nl()
{
    write(1, "\n", 1);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_3_spaces()
{
    int i = 0;
    char space = 32;
    while(i < 3)
    {
        ft_putchar(space);
        i++;
    }
}

int  main(int argc, char *argv[])
{
    if(argc != 2)
    {
        nl();
        return (0);
    }
    while(*argv[1])
    {
        ft_putchar(*argv[1]);
        if(*(argv[1] + 1) != 0)
            ft_3_spaces();
        argv[1]++;
    }
    nl();
    return (0);
}