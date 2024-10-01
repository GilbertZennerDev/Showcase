#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char	make_lower_alpha(char c);
bool	browse_vowels(char c);
int	func_count_vowels(char *text);

char	make_lower_alpha(char c)
{
	return (c >= 'A' && c <= 'Z') ? c + 32 : c;
}

bool	browse_vowels(char c)
{
	static char	vowels[] = {'i', 'u', 'e', 'o', 'a', '\0'};
	char	*vowelsptr = vowels;

	c = make_lower_alpha(c);
	while(*vowelsptr)
	{
		if(c == make_lower_alpha(*vowelsptr))
			return (1);
		vowelsptr++;
	}
	return	(0);
}

int	func_count_vowels(char *text)
{
	int	count;

	count = 0;
	while(*text)
	{
		if(browse_vowels(*text))
		{
			count++;
		}
		text++;
	}
	return (count);
}


int	main(void)
{
	char	text[] = "iueoa";
	printf("count = %d\n", func_count_vowels(text));
	return (0);
}
