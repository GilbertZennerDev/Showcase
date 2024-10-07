#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void    ft_ptr(int *ptr)
{
	*ptr = *ptr + 1;
}

void    main(void)
{
    int i = 0;
    int *iptr = &i;

    int j[] = {0, 1, 2, 3, 4, 5};
    int *jptr = j;

    int *dynamicPtr = (int *)malloc(sizeof(int));

    *dynamicPtr = 100;

    printf("%d", *dynamicPtr);
    free(dynamicPtr);

    ft_ptr(iptr);
    //printf("%d", i);
    //printf("%d", *iptr);
    printf("%d%d%d%d%d", *jptr, *jptr+1, *jptr+2, *jptr+3, *jptr+4);
}

