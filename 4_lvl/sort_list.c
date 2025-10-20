/* Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------


Escriba la siguiente función:


t_list  *sort_list(t_list* lst, int (*cmp)(int, int));


esta función tendrá que ordenar la lista pasada como parámetro, utlilizando el 
puntero a función cmp para determinar el orden que hay que aplicar y devolver 
un puntero al primer elemento de la lista ordenada.

Se deben conservar los duplicados.

Las entradas siempre serásn coherentes.

Debe utilizar el tipo t_list desccrito en el archivo list.h que se le 
hafacilitado. Tendrá que incluir este archivo (#include "list.h"), pero no 
entregarlo. Utilizaremos el nuestro propio para compilar su ejecución.

Si a y b se encuentran en el orden correct, las funciones pasadas como cmp 
devolverán siempre un valor distinto de 0.  

Por ejemplo, la siguiente función utilizada como cmp tendrá que permitir 
ordenar la lista por orden creciente: 

int ascending(int a, int b)
{
    return (a <= b);
} */

typedef struct    s_list
{
    struct s_list *next;
    int          data;
}                 t_list;

#include <stdio.h>
t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *start;
    int tmp = 0;

    start = lst;
    while (lst && lst->next)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
    return (start);
}
int ascending(int a, int b)
{
	return (a <= b);
}

void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d", lst->data);
        if (lst->next)
            printf(" ");
        lst = lst->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *head;
    t_list a;
    t_list b;
    t_list c;
    t_list d;
    t_list e;
    t_list f;
    t_list g;
    t_list h;


    head = &a;
    a.data = 0;
    a.next = &b;
    b.data = 1;
    b.next = &c;
    c.data = 3;
    c.next = &d;
    d.data = 5;
    d.next = &e;
    e.data = -124;
    e.next = &f;
    f.data = 800;
    f.next = &g;
    g.data = 223;
    g.next = &h;
    h.data = 10;
    h.next = NULL;

    printf("Lista antes de ordenar: ");
    print_list(head);

    head = sort_list(head, ascending);

    printf("Lista después de ordenar: ");
    print_list(head);
    return (0);
}









































// #include "ft_list.h"

// t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
// {
// 	t_list	*start;
// 	int swap = 0;

// 	start = lst;
// 	while (lst && lst->next)
// 	{
// 		if ((*cmp)(lst->data, lst->next->data) == 0)
// 		{
// 			swap = lst->data;
// 			lst->data = lst->next->data;
// 			lst->next->data = swap;
// 			lst = start;
// 		}
// 		else 
// 			lst = lst->next;
// 	}
// 	return (start);
// }

// #include <unistd.h>

// /* prototipo de la función a probar */
// t_list  *sort_list(t_list *lst, int (*cmp)(int, int));

// /* comparador ascendente: devuelve != 0 si a y b están en orden */
// int     ascending(int a, int b)
// {
//     if (a <= b)
//         return (1);
//     return (0);
// }

// int     main(void)
// {
//     t_list  a;
//     t_list  b;
//     t_list  c;
//     t_list  d;
//     t_list  *head;
//     int     v1;
//     int     v2;
//     int     v3;
//     int     v4;

//     v1 = 67;
//     v2 = 1;
//     v3 = 42;
//     v4 = 2;

//     a.data = v1;
//     a.next = &b;
//     b.data = v2;
//     b.next = &c;
//     c.data = v3;
//     c.next = &d;
//     d.data = v4;
//     d.next = 0;

//     head = &a;

//     /* antes */
//     print_list(head);

//     /* ordenar ascendente */
//     head = sort_list(head, ascending);

//     /* después */
//     print_list(head);

//     return (0);
// }
