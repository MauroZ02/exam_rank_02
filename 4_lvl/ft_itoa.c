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

int	suma_digitos(int nbr)
{
	int sum = 0;
	long tmp = (long)nbr;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		sum++;
		tmp = tmp * -1;
		while (tmp > 0)
		{
			sum++;
			tmp = tmp / 10;
		}
	}
	else if (nbr > 0)
	{
		while (tmp > 0)
		{
			sum++;
			tmp = tmp /10;
		}
	}
	return (sum);
}

char	*ft_itoa(int nbr)
{
	long tmp = (long)nbr;
	char *str;
	int i = 0;
	int sum = suma_digitos(nbr);
	str = malloc((sum + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[sum] = '\0';
	if (nbr == 0)
		str[i] = '0';
	else if (nbr < 0)
	{
		str[0] = '-';
		tmp = tmp * -1;
	}
	i = sum - 1;
	while (tmp > 0)
	{
		str[i] = tmp % 10 + '0';
		tmp = tmp / 10;
		i--;
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