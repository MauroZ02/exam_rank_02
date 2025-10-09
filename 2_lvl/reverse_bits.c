/* Assignment name : reverse_bits
Expected files : reverse_bits.c
Allowed functions:

Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.

Your function must be declared as follows:

unsigned char reverse_bits(unsigned char octet);

Example:

1 byte 
_____________
 0010  0110
     ||
     \/
 0110  0100 */

#include <stdio.h>
#include <stdlib.h>

unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;
	int result = 0;
	while(i > 0)
	{
		i--;
		result = result * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (result);
}

int main(int argc, char **argv)
{
    if (argc != 2) return 1;
    int val = atoi(argv[1]);           // solo decimal
    if (val < 0 || val > 255) return 1;

    unsigned char x = (unsigned char)val;
    unsigned char r = reverse_bits(x);

    printf("%u -> %u\n", x, r);
    return 0;
}