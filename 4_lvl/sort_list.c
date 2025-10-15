/* Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------

Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.

For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
	return (a <= b);
} */

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;

#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*start;
	int swap = 0;

	start = lst;
	while (lst && lst->next)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = start;
		}
		else 
			lst = lst->next;
	}
	return (start);
}

#include <unistd.h>

/* prototipo de la función a probar */
t_list  *sort_list(t_list *lst, int (*cmp)(int, int));

/* comparador ascendente: devuelve != 0 si a y b están en orden */
int     ascending(int a, int b)
{
    if (a <= b)
        return (1);
    return (0);
}

void    putnbr_rec(long nb)
{
    char d;

    if (nb >= 10)
        putnbr_rec(nb / 10);
    d = '0' + (nb % 10);
    write(1, &d, 1);
}

void    putnbr(int n)
{
    long nb;

    nb = n;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    putnbr_rec(nb);
}

void    print_list(t_list *lst)
{
    while (lst)
    {
        putnbr(lst->data);
        if (lst->next)
            write(1, " ", 1);
        lst = lst->next;
    }
    write(1, "\n", 1);
}

int     main(void)
{
    t_list  a;
    t_list  b;
    t_list  c;
    t_list  d;
    t_list  *head;
    int     v1;
    int     v2;
    int     v3;
    int     v4;

    v1 = 67;
    v2 = 1;
    v3 = 42;
    v4 = 2;

    a.data = v1;
    a.next = &b;
    b.data = v2;
    b.next = &c;
    c.data = v3;
    c.next = &d;
    d.data = v4;
    d.next = 0;

    head = &a;

    /* antes */
    print_list(head);

    /* ordenar ascendente */
    head = sort_list(head, ascending);

    /* después */
    print_list(head);

    return (0);
}
