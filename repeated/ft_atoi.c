/* Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str to an integer (type int)
and returns it.

It works much like the standard atoi(const char *str) function, see the man.

Your function must be declared as follows:

int	ft_atoi(const char *str); */

























// int	ft_atoi(const char *str)
// {
// 	int i = 0;
// 	int sign = 1;
// 	int res = 0;

// 	while (str[i] == ' ' || str[i] >= 9 && str[i] <= 13)
// 		i++;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		res = res * 10 + (str[i] - '0');
// 		i++;
// 	}
// 	return (sign * res);
// }
// #include <stdio.h>
// #include <stdlib.h>

// int main (int argc, char **argv)
// {
// 	if (argc != 2)
// 		return (1);
// 	printf(" ft_atoi: %d\n", ft_atoi(argv[1]));
// 	printf(" atoi   : %d\n", atoi(argv[1]));
// 	return 0;
// }