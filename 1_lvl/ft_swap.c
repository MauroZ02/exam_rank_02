/*Assignment name  : ft_swap
Expected files   : ft_swap.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.

Your function must be declared as follows:

void	ft_swap(int *a, int *b);*/

// #include <stdio.h>
// #include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// int main(int argc, char **argv)
// {
// 	int a = atoi(argv[1]);
// 	int b = atoi(argv[2]);
// 	printf("*before swap* a: %d - b: %d\n", a, b);
// 	ft_swap(&a, &b);
// 	printf("*after swap* a: %d - b: %d\n", a, b);
// 	return 0;
// }