#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	used[256];
	int	i;
	char	c;

	i = 0;
	while (i < 256)
	{
		used[i] = 0;
		i++;
	}

	i = 0;
	while (s1[i])
	{
		c = s1[i];
		if (!used[(unsigned char)c])
		{
			int	j;

			j = 0;
			while (s2[j])
			{
				if (s2[j] == c)
				{
					write(1, &c, 1);
					used[(unsigned char)c] = 1;
					break;
				}
				j++;
			}
		}
		i++;
	}
}

void inter(char *s1, char *s2)
{
    int used[256];
    int i;
    int j;
    char c;

    i = 0;
    while(i < 256)
    {
        used[i] = 0;
        i++;
    }

    i = 0;
    while(s1[i])
    {
        c = s1[i];
        if(!used[(unsigned char) c])
        {
            j = 0;
            while(s2[j])
            {
                if(s2[j] ==c)
                {
                    write(1, &c, 1);
                    used[(unsigned char) c] = 1;
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		inter(argv[1], argv[2]);
	}
	write(1, "\n", 1);
	return (0);
}