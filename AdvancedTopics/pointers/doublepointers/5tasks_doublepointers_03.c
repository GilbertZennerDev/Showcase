#include <stdio.h>
#include <stdlib.h>

void print_pointers(int **arr, int size)
{
	for(int i=0; i < size; i++)
        {
		printf("ptr%d: %p\n", i+1, arr[i]);
        }
}

int	main(void)
{
	int size = 3;
	int **ptr_arr = (int **)malloc(size * sizeof(int *));

	if(ptr_arr == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		return (1);
	}

	for(int i=0; i < size; i++)
	{
		ptr_arr[i] = (int *)malloc(sizeof(int));

		 if(ptr_arr[i] == NULL)
        	{
            		fprintf(stderr, "Memory allocation failed.\n");
			
			for (int j = 0; j < i; j++)
    			{
			        free(ptr_arr[j]);
    			}
		    	free(ptr_arr);
    			return 1;
        	}

		 *ptr_arr[i] = i + 1;
	}

	printf("Pointers and their values: \n");

	for(int i=0; i < size; i++)
        {
		printf("Pointer %d: %p, value : %d\n", i+1, (void *)ptr_arr[i], *ptr_arr[i]);
        }

	printf("Printing double pointers: \n");

	print_pointers(ptr_arr, size);

	for(int i = 0; i < 3; i++)
	{
		free(ptr_arr[i]);
	}

	free(ptr_arr);
	
	return (0);
}
