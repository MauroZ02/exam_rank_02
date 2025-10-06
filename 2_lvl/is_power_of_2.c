/* Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int	    is_power_of_2(unsigned int n); */

#include <unistd.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	int i = 1;
	int res = 0;
	int pot = 1;

	if (n == 0)
		return 0;
	while(res <= n)
	{
		res = 2 * pot;
		if (res == n)
		{
			return 1;
		}
		pot = pot * 2;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if ( argc == 2)
	{
		int num = atoi(argv[1]);
		if (is_power_of_2(num) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return 0;
}
