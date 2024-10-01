#include <unistd.h>

int main(void)
{
    char *text;
    char space;

    text = "abc";
    space = ' ';

    while (*text)
    {
        write(1, text, 1);
        if (*(text + 1) != '\0')
        {
            write(1, &space, 1);
            write(1, &space, 1);
            write(1, &space, 1);
        }
        text++;
    }
write(1, "\n", 1);
return (0);
}
