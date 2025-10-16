/* Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2); */

#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	int res = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
	{
		i++;
	}
	res = s1[i] - s2[i];
	return (res);
}
#include <stdio.h>
int main(int argc, char **argv)
{
	 char *s1 = argv[1];
	 char *s2 = argv[2];

	printf("strcmp:    %d\n", strcmp((char)s1, (char)s2));
	printf("ft_strcmp: %d\n", ft_strcmp((char)s1, (char)s2));
	return (0);
}
































int	ft_strcmp(char *s1, char *s2)
{
	int i = 0;

	while ((s1[i] == s2[i]) && (s1[i] && s2[i])) /* it's not necessary to check that s1 and s2 exists */
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <string.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("ft_strcmp: %d\n", ft_strcmp(argv[1], argv[2]));
		printf("strcmp   : %d\n", strcmp(argv[1], argv[2]));
	}
	return 0;
}