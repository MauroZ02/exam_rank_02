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


int	is_prime(int n)
{
	int i = 2;

	if (n <= 1)
		return (0);
	while (i <= n / i)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return 1;
}

void	ft_putnbr(int num)
{
	char digit;
	if (num < 0)
		return ;
	else if (num >= 0)
	{
		if (num >= 10)
			ft_putnbr(num / 10);
		digit = num % 10 + '0';
		write (1, &digit, 1);
	}
}

int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
		return (0);
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (1);
	}
	else if (argc == 2)
	{
		int num = ft_atoi(argv[1]);

		int res = 0;
		if (num <= 1)
			return (0);
		while (num > 0)
		{
			if (is_prime(num))
			{
				res = res + num;
			}
			num--;
		}
		ft_putnbr(res);
	}
	write(1, "\n", 1);
	return (0);
}