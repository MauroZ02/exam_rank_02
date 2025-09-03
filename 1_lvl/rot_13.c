/*Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.

'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.

The output will be followed by a newline.

If the number of arguments is not 1, the program displays a newline.

Example:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>*/

#include <unistd.h>

int main(int argc, char **argv)
{
	char *str = argv[1];
	char letter;
	int i = 0;
	if (argc == 2)
	{
		while(str[i])
		{
			if(str[i] >= 'a' && str[i] <= 'm')
			{
				letter = str[i] + 13;
				write(1, &letter, 1);
			}
			else if (str[i] >= 'n' && str[i] <= 'z')
			{
				letter = str[i] - 13;
				write(1, &letter, 1);
			}
			else if (str[i] >= 'A' && str[i] <= 'M')
			{
				letter = str[i] + 13;
				write(1, &letter, 1);
			}
			else if (str[i] >= 'N' && str[i] <= 'Z')
			{
				letter = str[i] - 13;
				write(1, &letter, 1);
			}
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}