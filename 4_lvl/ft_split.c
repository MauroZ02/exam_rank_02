/* Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */








































#include <stdlib.h>
#include <stdio.h>

char	*copy_word(char *s1, char *s2, int len)
{
	int i = 0;
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[len] = '\0';
	return (s2);
}

char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int word_count = 0;
	int start = 0;
	char *word;
	char **split;

	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0'))
			i++;
		if (str[i] == '\0')
			break;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			i++;
		word_count++;
	}
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
	{
		printf("null in first malloc");
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\0'))
			i++;
		if (str[i] == '\0')
			break;
		start = i;
		while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
			i++;
		if (i > start)
		{
			split[j] =  malloc(((i - start) + 1) * sizeof(char));
			if (!split[j])
				return (NULL);
			copy_word(&str[start], split[j], (i - start));
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

int main(int argc, char **argv)
{
	char *str = argv[1];
	char **split;
	split = ft_split(str);
	if (split == NULL)
	{
		printf("problema\n");
		return (1);
	}

	int y = 0;

		while (split[y] != NULL)
		{
			printf("%s\n", split[y]);
			y++;
		}
		while (split[y] != NULL)
		{
			free(split[y]);
			y++;
		}
	free(split);
	return (0);
}

// int	main(void)
// {
// 	// 1. Declaramos la cadena de prueba y el puntero para el resultado
// 	char *frase_de_prueba = "   Hola\tmundo que tal   \n estas? -Todo bien por suerte, vos?";
// 	char **resultado;
// 	int i;

// 	printf("Frase original: \"%s\"\n", frase_de_prueba);
// 	printf("----------------------------------------\n");

// 	// 2. Llamamos a nuestra función
// 	resultado = ft_split(frase_de_prueba);

// 	// 3. Verificamos que la función no devolvió un error (NULL)
// 	if (resultado == NULL)
// 	{
// 		printf("La función ft_split ha devuelto NULL (error de memoria).\n");
// 		return (1); // Terminamos el programa con un código de error
// 	}

// 	// 4. Recorremos el array de strings para imprimir cada palabra
// 	printf("Palabras encontradas:\n");
// 	i = 0;
// 	while (resultado[i] != NULL)
// 	{
// 		printf("Palabra %d: \"%s\"\n", i, resultado[i]);
// 		i++;
// 	}

// 	// 5. Liberamos la memoria (¡PASO CRÍTICO!)
// 	printf("----------------------------------------\n");
// 	printf("Liberando memoria...\n");
// 	i = 0;
// 	while (resultado[i] != NULL)
// 	{
// 		free(resultado[i]); // Primero liberamos cada palabra (char *)
// 		i++;
// 	}
// 	free(resultado); // Luego liberamos el array de punteros (char **)
// 	printf("Memoria liberada.\n");

// 	return (0); // El programa terminó correctamente
// }