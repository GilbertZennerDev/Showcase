#include <unistd.h>

int main(void)
{
    char *text;
    text = "123";
    while (*text)
        text++;
    while (text != "123" - 1)
    {
        text--;
        write(1, text, 1);
    }
    return (0);
}