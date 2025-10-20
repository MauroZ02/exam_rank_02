/* Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------

Write a function that takes a list and a function pointer, and applies this
function to each element of the list.

It must be declared as follows:

void    ft_list_foreach(t_list *begin_list, void (*f)(void *));

The function pointed to by f will be used as follows:

(*f)(list_ptr->data);

You must use the following structure, and turn it in as a file called
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; */

// #include "ft_list.h"
#include <stdio.h>
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list; 

void    ft_list_foreach(t_list *begin, void (*f)(void *))
{
    while (begin)
    {
        (*f)(begin->data);
        begin = begin->next;
    }
}


// void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
// {
//     t_list *point;
//     point = begin_list;
//     while (point)
//     {
//         (*f)(point->data);
//         point = point->next;
//     }
// }

/* main.c: pruebas para ft_list_foreach */
#include <unistd.h>
//#include "ft_list.h"

/* imprime s y salto de línea con write */
void    putstr_line(char *s)
{
    int i;
    i = 0;
    if (s == 0)
    {
        write(1, "(null)\n", 7);
        return;
    }
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i = i + 1;
    }
    write(1, "\n", 1);
}

/* callback 1: imprimir */
void    f_imprime(void *p)
{
    char *s;
    s = (char *)p;
    putstr_line(s);
}

/* callback 2: pasar a MAYÚSCULAS in-place (solo si hay string mutable) */
void    f_mayus(void *p)
{
    char *s;
    int  i;

    s = (char *)p;
    if (s == 0)
        return;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - ('a' - 'A');
        i = i + 1;
    }
}

int     main(void)
{
    t_list  n1;
    t_list  n2;
    t_list  n3;
    char    s1[4];
    char    s2[4];
    char    s3[5];
    char    *p1;
    char    *p2;
    char    *p3;

    /* s1 = "uno" */
    s1[0] = 'u';
    s1[1] = 'n';
    s1[2] = 'o';
    s1[3] = '\0';

    /* s2 = "dos" */
    s2[0] = 'd';
    s2[1] = 'o';
    s2[2] = 's';
    s2[3] = '\0';

    /* s3 = "tres" */
    s3[0] = 't';
    s3[1] = 'r';
    s3[2] = 'e';
    s3[3] = 's';
    s3[4] = '\0';

    p1 = s1;
    p2 = s2;
    p3 = s3;

    /* encadenar lista: n1 -> n2 -> n3 -> NULL */
    n1.data = (void *)p1;
    n1.next = &n2;
    n2.data = (void *)p2;
    n2.next = &n3;
    n3.data = (void *)p3;
    n3.next = 0;

    /* Test 1: imprime uno, dos, tres */
    write(1, "TEST 1\n", 7);
    ft_list_foreach(&n1, f_imprime);

    /* Test 2: data NULL en medio */
    write(1, "TEST 2\n", 7);
    n2.data = 0;
    ft_list_foreach(&n1, f_imprime);

    /* restaurar y Test 3: MAYÚSCULAS + imprimir */
    n2.data = (void *)p2;
    write(1, "TEST 3\n", 7);
    ft_list_foreach(&n1, f_mayus);
    ft_list_foreach(&n1, f_imprime);

    /* Test 4: lista vacía (no debe imprimir nada ni caerse) */
    write(1, "TEST 4\n", 7);
    ft_list_foreach(0, f_imprime);

    return (0);
}
