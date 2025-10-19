/* Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int i = 0;
	int len = 0;
	char *dest;

	while (src[len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Pon aquí tu función ft_strdup

int main(void)
{
    char *original;
    char *copia;
    
    printf("=== PRUEBA 1: Cadena normal ===\n");
    original = "Hola mundo";
    copia = ft_strdup(original);
    printf("Original: %s\n", original);
    printf("Copia   : %s\n", copia);
    printf("¿Son iguales? %d\n", strcmp(original, copia) == 0);
    free(copia);
    
    printf("\n=== PRUEBA 2: Cadena vacía ===\n");
    original = "";
    copia = ft_strdup(original);
    printf("Original: '%s'\n", original);
    printf("Copia   : '%s'\n", copia);
    printf("Longitud: %lu\n", strlen(copia));
    free(copia);
    
    printf("\n=== PRUEBA 3: Cadena larga ===\n");
    original = "Esta es una cadena muy larga para probar la función";
    copia = ft_strdup(original);
    printf("¿Son iguales? %d\n", strcmp(original, copia) == 0);
    free(copia);
    
    printf("\n=== PRUEBA 4: Con strlen ===\n");
    original = "Prueba";
    copia = ft_strdup(original);
    printf("strlen original: %lu\n", strlen(original));
    printf("strlen copia   : %lu\n", strlen(copia));
    free(copia);
    
    return 0;
}

// #include <stdlib.h>

// char	*ft_strdup(char *src)
// {
// 	int i = 0;
// 	int size = 0;
// 	char *dup;

// 	while (src[size])
// 		size++;
// 	dup = malloc(size * sizeof(char));
// 	while (src[i])
// 	{
// 		dup[i] = src[i];
// 		i++;
// 	}
// 	dup[i] = '\0';
// 	return (dup);
// }

// #include <stdio.h>
// #include <string.h>
// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		printf("ft_strdup: %s\n", ft_strdup(argv[1]));
// 		printf("strdup   : %s\n", strdup(argv[1]));
// 	}
// 	return 0;
// }