#include <unistd.h>

int is_printable(char c)
{
    return (c >= ' ' && c <= '~');
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_print_hex(char arr[])
{
    int i;

    i = 0;
    while(arr[i])
    {
        ft_putchar(arr[i]);
        i++;
    }
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char c;

    char hex[16];
    char printhex[4];
    int h;

    i = 0;
    h = 0;
    c = '0';
    while(i <= 9)
    {
        hex[i] = c;
        i++;
        c++;
    }
    while(i <= 15)
    {
        hex[i] = 97 + h;
        h++;
        i++;
    }

    printhex[0] = '\\';
    printhex[3] = '\0';

    i = 0;
    while(str[i])
    {
        c = str[i];
        if(is_printable(c))
            ft_putchar(c);
        else
        {
            printhex[1] = hex[c / 16];
            printhex[2] = hex[c % 16];
            ft_print_hex(printhex);
        }
        i++;
    }
    write(1, "\n", 1);
}

int main(void)
{
    ft_putstr_non_printable("Hello \a\b\t\n\v\f\r Dolly");
    return (0);
}