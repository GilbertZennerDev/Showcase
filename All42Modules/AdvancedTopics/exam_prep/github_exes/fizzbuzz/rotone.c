/*
Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.

'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.

The output will be followed by a \n.

If the number of arguments is not 1, the program displays \n.

Example:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
*/

#include <unistd.h>

void nl()
{
    write(1, "\n", 1);
}

void ft_jump_char(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        if(c != 'z')
            c++;
        else
            c = 'a';
    }
    else if(c >= 'A' && c <= 'Z')
    {
        if(c != 'Z')
            c++;
        else
            c = 'A';
    }
    write(1, &c, 1);
}

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        nl();
        return (0);
    }
    while(*argv[1])
    {
        ft_jump_char(*argv[1]);
        argv[1]++;
    }
    nl();
    return (0);
}