#include <stdio.h>

void	swap_string(char **firststring, char **secondstring)
{
	char *tmp = *firststring;
	*firststring = *secondstring;
	*secondstring = tmp;
}

int	main(void)
{
	char* string1 = "string one";
	char* string2 = "string two";

	printf("Before: string1 = %s\n", string1);
	printf("Before: string2 = %s\n", string2);

	swap_string(&string1, &string2);
	
	printf("After: string1 = %s\n", string1);
        printf("After: string2 = %s\n", string2);
	
	return (0);
}
