/* Assignment name  : ft_strrev
Expected files   : ft_strrev.c
Allowed functions:
--------------------------------------------------------------------------------

Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

char	*ft_strrev(char *str)
{
	int len = 0;
	int i = 0;
	char swap;

	while (str[len])
		len++;

	while (i < len)
	{
		len--;
		swap = str[i];
		str[i] = str[len];
		str[len] = swap;
		i++;
	}
	return (str);
}

#include <stdio.h>
int main(int argc, char **argv)
{
	printf("%s", ft_strrev(argv[1]));
	return (0);
}