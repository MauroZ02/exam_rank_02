/* Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline.

Examples:

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$> */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *str = argv[1];
		int i = 0;
		int space = 0;
		while (str[i] == ' ' || str[i] == '	')
			i++;
		while (str[i])
		{
			if (str[i] == ' '  || str[i] == '	')
				space = 1;
			else 
			{
				if (space == 1)
				{
					write(1, "   ", 3);
				}
				write(1, &str[i], 1);
				space = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}