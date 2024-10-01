#include <stdio.h>

char *ft_reverse_string(char *string)
{
	char *start = string;
	char *end = string;
	char temp;

	while(*end)
	{
		end++;
	}
	end--;
	while(start < end)
	{
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return (string);
}

int	main(void)
{
	char text[] = "123";
	printf("String reversed = %s\n", ft_reverse_string(text));
	return (0);
}
