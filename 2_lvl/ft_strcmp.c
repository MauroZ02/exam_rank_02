/* Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2); */

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;
	while((s1[i] == s2[i]) && (s1[i] && s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>
#include <string.h>

int	main (int argc, char **argv)
{
	if (argc == 3)
	{
		int res = 0;
		res = ft_strcmp(argv[1], argv[2]);
		printf("ft_strcmp difference is: %d\n", res);

		int real = 0;
		real = strcmp(argv[1], argv[2]);
		printf("strcmp difference is: %d\n", real);
	}
	return 0;
}