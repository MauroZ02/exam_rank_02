/* Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$> */

#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1][0])
	{
		char	*str;
		int		i;
		int		start;
		int		end;
		int		printed;

		str = argv[1];
		i = 0;
		while (str[i] && is_space(str[i]))
			i++;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		end = i;
		if (start == end)
		{
			write(1, "\n", 1);
			return (0);
		}
		printed = 0;
		while (str[i])
		{
			while (str[i] && is_space(str[i]))
				i++;
			if (!str[i])
				break ;
			if (printed == 1)
				write(1, " ", 1);
			while (str[i] && !is_space(str[i]))
			{
				write(1, &str[i], 1);
				i++;
			}
			printed = 1;
		}
		if (printed == 1)
			write(1, " ", 1);
		while (start < end)
		{
			write(1, &str[start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
