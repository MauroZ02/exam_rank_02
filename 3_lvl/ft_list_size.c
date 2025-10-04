/* Assignment name  : ft_list_size
Expected files   : ft_list_size.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i = 0;
	t_list *current;
	current = begin_list;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return i;
}
#include <stdio.h>
int main(void)
{
	t_list head;
	t_list n2;
	t_list n3;
	t_list n4;
	t_list n5;
	t_list n6;
	t_list n7;
	t_list n8;
	t_list n9;

	head.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n8;
	n8.next = &n9;
	n9.next = NULL;

	printf ("list size : %d\n", ft_list_size(&head));
	return 0;
}