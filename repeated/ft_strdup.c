/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */


































// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// char	*ft_strdup(char *src)
// {
// 	int i = 0;
// 	int size = 0;
// 	char *dup;

// 	while (src[size])
// 		size++;
// 	dup = malloc(size * sizeof(char));
// 	while (src[i])
// 	{
// 		dup[i] = src[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("ft_strdup: %s\n", ft_strdup(argv[1]));
// 		printf("strdup   : %s\n", strdup(argv[1]));
// 	}
// 	return 0;
// }