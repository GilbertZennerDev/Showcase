#include <unistd.h>

int is_lower_alpha(char c)
{
    return (c >= 'a' && c <= 'z');
}

int is_upper_alpha(char c)
{
    return (c >= 'A' && c <= 'Z');
}

int is_alpha(char c)
{
    return (is_lower_alpha(c) || is_upper_alpha(c));
}

char *ft_strcapitalize(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if(!i)
        {
            if(is_lower_alpha(str[i]))
                str[i] -= 32;
        }
        else
        {
            if(is_lower_alpha(str[i]) && !is_alpha(str[i - 1]))
                str[i] -= 32;
            else if(is_upper_alpha(str[i]) && is_alpha(str[i - 1]))
                str[i] += 32;
        }
        i++;
    }
    return (str);
}