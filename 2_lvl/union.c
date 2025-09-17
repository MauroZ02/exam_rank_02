/* Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$> */

#include <unistd.h>

int is_repeated(char *str, char c, int i)
{
	int j = 0;
	while (j < i)
	{
		if (str[j] == c)
			return 1;
		j++;
	}
	return 0;
}


int main(int argc, char **argv)
{
	int i = 0;
	int j;
	char *str = argv[1];
	char *s2 = argv[2];

	if (argc == 3)
	{
		while (str[i])
		{
			if (!is_repeated(str, str[i], i))
				write(1, &str[i], 1);
			i++;
		}
		while (s2[j])
		{
			if ((!is_repeated(s2, s2[j], j)) && (!is_repeated(str, s2[j], i)))
				write(1, &s2[j], 1);
			j++;
		}
	}
	write(1, "\n", 1);
	return 0;
}

// #include <unistd.h>

// int main(int argc, char *argv[])
// {
// 	int j = 0;
// 	int i = 0;

// 	if (argc == 3)
// 	{
// 		while (argv[1][i])
// 		{
// 			if (!is_repeated(argv[1], argv[1][i], i))
// 				write(1, &argv[1][i], 1);
// 			i++;
// 		}
// 		while(argv[2][j])
// 		{
// 			if ((!is_repeated(argv[2], argv[2][j], j)) && (!is_repeated(argv[1], argv[2][j], i)))
// 				write(1, &argv[2][j], 1);
// 			j++;
// 		}
// 	}
// 	write(1, "\n", 1);
// 	return (0);
// }