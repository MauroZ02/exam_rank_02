/* Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$ */

#include <unistd.h>
int	is_repeated(const char *s, const char c, int i)
{
	int j;
	j = 0;
	while (j < i)
	{
		if (s[j] == c)
			return 1;
		j++;
	}
	return 0;
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int i = 0;
		int j;
		char *s1 = argv[1];
		char *s2 = argv[2];
		
		while (s1[i])
		{
			j = 0;
			while (s2[j])
			{
				if (s1[i] == s2[j])
				{
					if (is_repeated(s1, s2[j], i) == 0)
					{
						write (1, &s1[i], 1);
						break ;
					}
				}
				j++;
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return 0;
}