#include <stdio.h>

struct Point {
	int x;
	int y;
};

void	print_values(struct Point point)
{
	printf("Point: x=%d; y=%d;\n", point.x, point.y);
}

int	main(void)
{
	print_values((struct Point){ 10, 20 });
	return 0;
}
