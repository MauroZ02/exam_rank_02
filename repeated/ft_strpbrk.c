/* Assignment name	: ft_strpbrk
Expected files	: ft_strpbrk.c
Allowed functions: None
---------------------------------------------------------------

Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2); */

#include <stdio.h>
#include <string.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	int j = 0;
	char *res = (char *)s1;

	while (s1[i])
	{
		j = 0;
		while(s2[j])
		{
			if (s1[i] == s2[j])
			{
				return ((char *)&s1[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

// int main(int argc, char **argv)
// {
// 	printf("strpbrk: %s\n", strpbrk(argv[1], argv[2]));
// 	printf("ft_strpbrk: %s\n", ft_strpbrk(argv[1], argv[2]));
// 	return (0);
// }

#include <stdio.h>
#include <string.h>

// Pon aquí tu función ft_strpbrk

int main(void)
{
    const char *resultado_real;
    const char *resultado_tuyo;
    
    printf("=== PRUEBA 1: Cadena normal ===\n");
    resultado_real = strpbrk("Hola mundo", "dm");
    resultado_tuyo = ft_strpbrk("Hola mundo", "dm");
    printf("strpbrk:    %s\n", resultado_real);
    printf("ft_strpbrk: %s\n", resultado_tuyo);
    printf("¿Iguales? %d\n\n", resultado_real == resultado_tuyo);
    
    printf("=== PRUEBA 2: Sin coincidencias ===\n");
    resultado_real = strpbrk("Hola", "xyz");
    resultado_tuyo = ft_strpbrk("Hola", "xyz");
    printf("strpbrk:    %p\n", resultado_real);
    printf("ft_strpbrk: %p\n", resultado_tuyo);
    printf("Ambos NULL? %d\n\n", (resultado_real == NULL && resultado_tuyo == NULL));
    
    printf("=== PRUEBA 3: Primera vocal ===\n");
    resultado_real = strpbrk("Python", "aeiou");
    resultado_tuyo = ft_strpbrk("Python", "aeiou");
    printf("strpbrk:    %s\n", resultado_real);
    printf("ft_strpbrk: %s\n", resultado_tuyo);
    
    printf("\n=== PRUEBA 4: Primer carácter ===\n");
    resultado_real = strpbrk("Hola", "H");
    resultado_tuyo = ft_strpbrk("Hola", "H");
    printf("strpbrk:    %s\n", resultado_real);
    printf("ft_strpbrk: %s\n", resultado_tuyo);
    
    printf("\n=== PRUEBA 5: Último carácter ===\n");
    resultado_real = strpbrk("Hola", "a");
    resultado_tuyo = ft_strpbrk("Hola", "a");
    printf("strpbrk:    %s\n", resultado_real);
    printf("ft_strpbrk: %s\n", resultado_tuyo);
    
    printf("\n=== PRUEBA 6: s2 vacío ===\n");
    resultado_real = strpbrk("Hola", "");
    resultado_tuyo = ft_strpbrk("Hola", "");
    printf("strpbrk:    %p\n", resultado_real);
    printf("ft_strpbrk: %p\n", resultado_tuyo);
    printf("Ambos NULL? %d\n", (resultado_real == NULL && resultado_tuyo == NULL));
    
    return 0;
}




























// char *ft_strpbrk(const char *s1, const char *s2)
// {
//     int i = 0;
//     int j = 0;
//     char *re = (char *)s1;

//     while (s1[i])
//     {
//         j = 0;
//         while (s2[j])
//         {
//             if (s1[i] == s2[j])
//                 return re;
//             j++;
//         }
//         i++;
//         re++;
//     }
//     return NULL;
// }
// int	main(int argc, char **argv)
// {
// 	printf("ft_strpbrk : %s\n", ft_strpbrk(argv[1], argv[2]));
// 	printf("strpbrk    : %s\n", strpbrk(argv[1], argv[2]));
// 	return 0;
// }