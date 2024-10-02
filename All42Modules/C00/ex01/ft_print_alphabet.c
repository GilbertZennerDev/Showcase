#include <unistd.h>

void    ft_print_alphabet()
{
    char c = 'a';
    while(c <= 'z')
    {
        write(1, &c, 1);
        c++;
    }
}

int main(void)
{
    ft_print_alphabet();
    write(1, "\n", 1);
    return (0);
}