/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n.

Examples:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$> */

#include <unistd.h>
#include <stdio.h>
int	ft_atoi(char *str)
{
	int i = 0;
	int res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return 0;
		i++;
	}
	while(str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

void	ft_putnbr(int num)
{
	char digit;
	if (num >= 10)
		ft_putnbr(num /10);
	digit = num % 10 + '0';
	write(1, &digit, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 0;
		while (argv[1][i] != '\0')
			i++;
		int num = ft_atoi(argv[1]);
		int res = 1;
		int total = 0;
		if (num > 214483647)
				return 1;
		while(res <= 9)
		{
			ft_putnbr(res);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			total = num * res;
			if (total > 214483647)
				return 1;
			ft_putnbr(total);
			write(1, "\n", 1);
			res++;
		}
	}
	else 
		write(1, "\n", 1);
	return 0;
}
