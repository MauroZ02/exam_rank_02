/* Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0. */
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int i = 0;
	int max = tab[i];

	while (i < len)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int main (int argc, char **argv)
{
	int tab[6] = {1, 2, 3, 42, 5, 6};

	printf("%d\n", max(tab, 6));
	return 0;
}