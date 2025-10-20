/* Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	space(int nbr)
{
	long num = (long)nbr;
	int space = 0;

	if (num < 0)
	{
		num = num * -1;
		space++;
	}
	else if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / 10;
		space++;
	}
	return (space);
}

char	*ft_itoa(int nbr)
{
	long n = (long)nbr;
	char *str;
	int i = 0;
	int place = space(nbr);
	str = malloc((place + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[place] = '\0';
	if (nbr == 0)
		str[i] = '0';
	else if (nbr < 0)
	{
		str[i] = '-';
		n = n * -1;
	}
	i = place;
	while (n > 0)
	{
		i--;
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int main(int argc, char **argv)
{
	int num = atoi(argv[1]);

	char *str;
	str = ft_itoa(num);
	if (!str)
		return (1);
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}

	return (0);
}