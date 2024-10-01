#include <unistd.h>

int main(void)
{
    char *text;

    text = "CODING";
    while(1)
    {
        write(1, *(text), 1);
    }
}