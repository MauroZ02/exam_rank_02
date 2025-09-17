/* Assignment name  : do_op
Expected files   : *.c, *.h
Allowed functions: atoi, printf, write
--------------------------------------------------------------------------------

Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int.

Examples:

$> ./do_op "123" "*" 456 | cat -e
56088$
$> ./do_op "9828" "/" 234 | cat -e
42$
$> ./do_op "1" "+" "-43" | cat -e
-42$
$> ./do_op | cat -e
$*/

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		char	*s1 = argv[1];
		char	*sign = argv[2];
		char	*s2 = argv[3];
		int		res = 0;
		int		n1 = atoi(s1);
		int		n2 = atoi(s2);

		if (sign[0] == '+')
			res = n1 + n2;
		else if (sign[0] == '-')
			res = n1 - n2;
		else if (sign[0] == '*')
			res = n1 * n2;
		else if (sign[0] == '/')
			res = n1 / n2;
		else if (sign[0] == '%')
			res = n1 % n2;
		printf("%d", res);
	}
	printf("\n");
}
