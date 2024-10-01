#include <unistd.h>
#include <stdio.h>

void	read_sensor(volatile int *sensorvalue)
{
	*sensorvalue = *sensorvalue + 1;
}

int	main(void)
{
	volatile int sensorvalue = 0;

	for(int i=0; i<10; i++)
	{
		read_sensor(&sensorvalue);
		sleep(5);
		printf("Sensor value = %d\n", sensorvalue);
	}
	return 0;
}
