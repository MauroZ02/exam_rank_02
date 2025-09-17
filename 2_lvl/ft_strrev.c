/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

#include <stdio.h>

char	*ft_strrev(char *str)
{
	int i = 0;
	int j = 0;
	char tmp;
	
	while (str[j])
		j++;
	while (i < j)
	{
		j--;
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
	}
	return (str);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("ft_strrev: %s\n", ft_strrev(argv[1]));
	}
	return 0;
}
