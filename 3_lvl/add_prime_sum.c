/* Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline.

Yes, the examples are right.

Examples:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$> */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int i = 0;
	int	acc = 0;

	while (str[i])
	{
		acc = acc * 10 + (str[i] - '0');
		i++;
	}
	return (acc);
}

void	ft_putnbr(int num)
{
	char c;
	if (num >= 10)
		ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int	is_prime(int num)
{
	int i = 2;

	if (num <= 1)
		return 0;
	while (i * i <= num)
	{
		if (num % i == 0)
			return 0;
		i++;
	}
	return 1;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return 1;
	}
	if (argc == 2)
	{
		int num = ft_atoi(argv[1]);
		int res = 0;

		while (num > 0)
		{
			if (is_prime(num))
				res += num;
			num--;
		}
		ft_putnbr(res);
	}
	write(1, "\n", 1);
	return (0);
}