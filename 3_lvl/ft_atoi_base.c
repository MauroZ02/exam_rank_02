/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base);
 */

#include <stdio.h>

static int	ft_isdigit(char c, int base)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;
	int value;
 
    // check if the base is valid
	if (!str || str_base < 2 || str_base > 16)
		return (0);
    // skip spaces
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
    // check for the sign
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
    // check if the char exists in the base
	while ((value = ft_isdigit(*str, str_base)) >= 0 && value < str_base)
	{
        // if so, add the value to the result
		result = result * str_base + value;
		str++;
	}
	// if there is a weird char we skip it
	while (*str == ' ' || (*str >= 9 && *str <= 13) || *str == '!')
		str++;
	return (result * sign);
}
/* --------------------------------------------------------- */

// #include <stdlib.h>
// #include <stdio.h>
// int main(int argc, char **argv)
// {
// 	printf("atoi base: %d", ft_atoi_base(argv[1], atoi(argv[2])));
// 	return 0;
// }

// ----------------8<-------------[ START TEST 
//         💻 TEST
// ./a.out "13268!" "16"         
//  YOUR OUTPUT:
// 0$
//         🗝 EXPECTED OUTPUT:
// 78440$
// ----------------8<------------- END TEST ]

// ----------------8<-------------[ START TEST 
//         💻 TEST
// ./a.out "13268!" "16"         
// YOUR OUTPUT:
// 0$
//         🗝 EXPECTED OUTPUT:
// 78440$
// ----------------8<------------- END TEST ]