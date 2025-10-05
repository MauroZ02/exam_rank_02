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

size_t	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	int j = 0;

	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("ft_strcspn: %zu\n", ft_strcspn(argv[1], argv[2]));
		printf("strcspn   : %lu\n", strcspn(argv[1], argv[2]));
	}
	return 0;
}