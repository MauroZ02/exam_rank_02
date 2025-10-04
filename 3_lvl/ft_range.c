/* Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3. */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int len = 0;
	int i = 0;
	if (start <= end)
		len = end - start + 1;
	else 
		len = start - end + 1;
	int *space = malloc(len * sizeof(int));

	while(i < len)
	{
		if (start <= end)
		{
			space[i] = start;
			start++;
		}
		else
		{
			space[i] = start;
			start--;
		}
		i++;
	}
	return (space);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	int start = atoi(argv[1]);
	int end = atoi(argv[2]);
	int *range = ft_range(start, end);
	int i = 0;
	int len = 0;

	if (start <= end)
		len = end - start + 1;
	else 
		len = start - end + 1;
	printf("range: ");
	while (i < len)
	{
		printf("%d, ", range[i]);
		i++;
	}
	printf("\n");
	free(range);
	return (0);
}

