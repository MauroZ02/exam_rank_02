/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */

#include <stdlib.h>
#include <stdio.h>
char	*ft_strdup(char *src)
{
	int	size = 0;
	int	i = 0;
	char *dup;

	while(src[size])
		size++;
	dup = malloc(sizeof(char) * (size));
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

#include <string.h>

int	main(int argc, char **argv)
{
	printf("ft_strdup : %s", ft_strdup(argv[1]));
	printf("\n");
	printf("strdup    : %s", strdup(argv[1]));
	printf("\n");
	return (0);
}