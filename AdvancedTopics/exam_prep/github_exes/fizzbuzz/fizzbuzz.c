/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that prints the numbers from 1 to 100, each separated by a
newline.

If the number is a multiple of 3, it prints 'fizz' instead.

If the number is a multiple of 5, it prints 'buzz' instead.

If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead.

Example:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
*/

#include <unistd.h>

void    ft_print_fizz()
{
    write(1, "fizz", 4);
}

void    ft_print_buzz()
{
    write(1, "buzz", 4);
}

void    ft_print_fizzbuzz()
{
    ft_print_fizz();
    ft_print_buzz();
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if(nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}

int main(void)
{
    int i = 1;
    while(i <= 100)
    {
        if(i % 3 == 0 && i % 5 == 0)
            ft_print_fizzbuzz();
        else if(i % 3 == 0)
            ft_print_fizz();
        else if(i % 5 == 0)
            ft_print_buzz();
        else
            ft_putnbr(i);
        i++;
        write(1, "\n", 1);
    }
}