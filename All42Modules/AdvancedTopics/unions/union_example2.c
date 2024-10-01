#include <stdio.h>
#include <string.h>

union Measurement{
	int weight;
	float length;
};

int	main(void)
{
	union Measurement measure;

	measure.length = 5.7;

	printf("length = %f\n",measure.length);

	measure.weight = 75;

	printf("weight = %d\n",measure.weight);
	return 0;
}
