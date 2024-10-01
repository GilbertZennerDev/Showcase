/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string, and displays the string in reverse
followed by a newline.

If the number of parameters is not 1, the program displays a newline.

Examples:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
*/

#include <unistd.h>

void nl()
{
    write(1, "\n", 1);
}

int ft_strlen(char *str)
{
    int len = 0;
    while(str[len])
        len++;
    return (len);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    int i;
    int len;
    if(argc != 2)
    {
        nl();
        return (0);
    }
    i = 0;
    len = ft_strlen(argv[1]);
    while(argv[1][i])
    {
        ft_putchar(argv[1][len - 1 - i]);
        i++;
    }
    nl();
    return (0);
}