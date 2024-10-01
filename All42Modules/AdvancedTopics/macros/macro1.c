#include <stdio.h>

#define PI 3.1415926535
#define SQUARE(x) ((x)*(x))
#define CIRCLE_AREA(x) (SQUARE(x)*PI)
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define DEBUG

int	main(void)
{
	float radius = 5.0;
	double area = CIRCLE_AREA(radius);
	printf("For radius %f, area of circle = %f.\n", radius, area);

	float a = 10.0, b = 25.03;
	printf("For a = %f and b = %f , min = %f\n", a, b, MIN(a,b));
	
	#ifdef DEBUG
		printf("Debug: radius = %f\n", radius);
	#endif


	return 0;
}
