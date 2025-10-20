/* Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal.

You have to use the ft_list.h file, which will contain:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$> */
#include <stdio.h>
#include <stdlib.h>
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;


void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}
}

int	compare(void *a, void *b)
{
	if (a == b)
		return 0;
	else
		return 1;
}

int	main(void)
{
	t_list *head;
	t_list *cur;

	head = malloc(sizeof(t_list));
	head->data = (void *)3;
	head->next = malloc(sizeof(t_list));

	head->next->data = (void *)5;
	head->next->next = malloc(sizeof(t_list));

	head->next->next->data = (void *)5;
	head->next->next->next = malloc(sizeof(t_list));

	head->next->next->next->data = (void *)3;
	head->next->next->next->next = malloc(sizeof(t_list));

	head->next->next->next->next->data = (void *)3;
	head->next->next->next->next->next = malloc(sizeof(t_list));

	head->next->next->next->next->next->data = (void *)5;
	head->next->next->next->next->next->next = NULL;

	printf("Lista completa:\n");
	cur = head;
	while (cur)
	{
		printf("%d ", (int)(long)cur->data);
		cur = cur->next;
	}
	printf("\n");

	ft_list_remove_if(&head, (void*)5, compare);

	printf("Lista después:\n");
	cur = head;
	while (cur)
	{
		printf("%d ", (int)(long)cur->data);
		cur = cur->next;
	}
	printf("\n");
}
