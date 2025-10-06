#include <unistd.h>

int is_upper (char c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}

int first_word(char *s, int i)
{
	if (i == 0)
		return 1;
	if ((s[i] != ' ' && s[i] != '\t') && (s[i - 1] == ' ' || s[i - 1] == '\t'))
		return 1;
	else
		return 0;
}
int main (int argc, char **argv)
{
	int i = 0;
	int j = 1;

	while (argc > 1)
	{
		i = 0;
		while (argv[j][i])
		{
			if ((argv[j][i] >= 'a' && argv[j][i] <= 'z') || (argv[j][i] >= 'A' && argv[j][i] <= 'Z'))
			{
				if (first_word(argv[j], i))
				{
					if (!is_upper(argv[j][i]))
						argv[j][i] -= 32;
				}
				else if (is_upper(argv[j][i]))
					argv[j][i] += 32;
			}
			write(1, &argv[j][i], 1);
			i++;
		}
		j++;
		argc--;
		write(1, "\n", 1);
	}
	return 0;
}