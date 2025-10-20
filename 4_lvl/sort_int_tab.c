/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent. */

void	sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int swap = 0;

	if (size < 2)
		return;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	n1;
	int	n2;
	int	n3;
	int	n4;
	int	n5;
	int	tab[5];
	int	i;

	if (argc != 6)
	{
		printf("\n");
		return (0);
	}
	n1 = atoi(argv[1]);
	n2 = atoi(argv[2]);
	n3 = atoi(argv[3]);
	n4 = atoi(argv[4]);
	n5 = atoi(argv[5]);

	tab[0] = n1;
	tab[1] = n2;
	tab[2] = n3;
	tab[3] = n4;
	tab[4] = n5;

	sort_int_tab(tab, 5);

	i = 0;
	while (i < 5)
	{
		printf("%d", tab[i]);
		if (i != 4)
			printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}
