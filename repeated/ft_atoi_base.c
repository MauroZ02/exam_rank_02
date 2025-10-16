/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base); */

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res = 0;
	int sign = 1;
	char digit;

	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str_base < 2 || str_base > 16)
			return (0);
	while (((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F')) && str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		if (digit >= str_base)
			return (0);
		res = res * str_base + digit;
		i++;
	}
	return (res * sign);
}

#include <stdio.h>
int	main(void)
{
	printf("Base 2,  num 101----->  %d\n", ft_atoi_base("101", 2));
	printf("Base 2,  num -101---->  %d\n", ft_atoi_base("-101", 2));
	printf("Base 8,  num 17------>  %d\n", ft_atoi_base("17", 8));
	printf("Base 8,  num 128----->  %d\n", ft_atoi_base("128", 8));
	printf("Base 16, num 7F------>  %d\n", ft_atoi_base("7F", 16));
	printf("Base 16, num 7f------>  %d\n", ft_atoi_base("7f", 16));
	printf("Base 10, num A------->  %d\n", ft_atoi_base("A", 10));
	printf("Base 17, num 101----->  %d\n", ft_atoi_base("101", 17));
	printf("Base 1,  num 101----->  %d\n", ft_atoi_base("101", 1));
	return (0);
}