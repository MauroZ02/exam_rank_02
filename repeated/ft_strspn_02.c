/* Assignment name	: ft_strspn
Expected files	: ft_strspn.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept); */

#include <string.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("ft_strspn : %zu\n", ft_strspn(argv[1], argv[2]));
		printf("strspn    : %lu\n", strspn(argv[1], argv[2]));
	}
	return 0;
}