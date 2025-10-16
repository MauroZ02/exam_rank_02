/* Assignment name	: ft_strcspn
Expected files	: ft_strcspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject); */

#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s1, const char *reject)
{
	size_t	i;
	size_t	j;

	if (!s1 || !reject)
		return (0);
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (reject[j] && s1[i] != reject[j])
			j++;
		if (s1[i] == reject[j])
			return (i);
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	printf("strcspn: %lu\n", strcspn(argv[1], argv[2]));
	printf("ft_strcspn: %lu\n", ft_strcspn(argv[1], argv[2]));

	return (0);
}



























// #include <string.h>
// #include <stdio.h>

// size_t	ft_strcspn(const char *s, const char *reject)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (s[i])
// 	{
// 		j = 0;
// 		while (reject[j])
// 		{
// 			if (s[i] == reject[j])
// 				return (i);
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (i);
// }

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("ft_strcspn: %zu\n", ft_strcspn(argv[1], argv[2]));
// 		printf("strcspn   : %lu\n", strcspn(argv[1], argv[2]));
// 	}
// 	return 0;
// }