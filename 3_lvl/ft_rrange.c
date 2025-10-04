/* Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */

#include <stdlib.h>
#include <stdio.h>

int	*ft_rrange(int start, int end)
{
	int len = 0;
	if (end <= start)
		len = start - end + 1;
	else
		len = end - start + 1; 
	int *space = malloc(len * sizeof(int));
	int i = 0;
	if (end <= start)
	{
		while (i < len)
		{
			space[i] = end;
			end++;
			i++;
		}
	}
	else
	{
		while(i < len)
		{
			space[i] = end;
			end--;
			i++;
		}
	}
	return (space);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int start = atoi(argv[1]);
		int end = atoi(argv[2]);
		int len = 0;
		int i = 0;
		if (end <= start)
			len = start - end + 1;
		else
			len = end - start + 1;
		printf("range: ");
		int *range = ft_rrange(start, end);
		while (i < len)
		{
			if (i+1 == len)
				printf ("%d", range[i]);
			else 
				printf ("%d, ", range[i]);
			i++;
		}
	}
	printf("\n");
	return 0;
}