#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sort a list by insertion
 * @list: the list to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp1, *tmp2;
	int  flag = 1, size;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	size = countnodes(*list);

	if (size > 1)
	{
		while (flag != 0)
		{
			flag = 0;
			while (tmp)
			{
				if (tmp->next == NULL)
					return;
				if (tmp->n > tmp->next->n)
				{
					tmp1 = tmp;
					tmp2 = tmp->next;
					nodeswaper(&tmp1, &tmp2, list, size);
					print_list(*list);
					flag = 1;
					tmp = *list;
				}
				else
					tmp = tmp->next;
			}
		}
	}
}

/**
 * countnodes - function that count nodes in a list.
 * @list: the list.
 * Return: the nodes count.
 */

int countnodes(listint_t *list)
{
	int a;

	if (list == NULL)
		return (0);

	for (a = 0; list != NULL; a++)
	{
		list = list->next;
	}
	return (a);
}

/**
 * nodeswaper - this function swap nodes in a list.
 * @tmp1: node 1.
 * @tmp2: node 2.
 * @list: list.
 * @size: size of the list.
 */

void nodeswaper(listint_t **tmp1, listint_t **tmp2, listint_t **list, int size)
{
	if (size > 2)
	{
		if ((*tmp1)->prev == NULL)
		{
			(*tmp2)->next->prev = *tmp1;
			*list = *tmp2;
		}
		else if ((*tmp1)->next->next == NULL)
			(*tmp1)->prev->next = *tmp2;
		else
		{
			(*tmp2)->next->prev = *tmp1;
			(*tmp1)->prev->next = *tmp2;
		}
		(*tmp2)->prev = (*tmp1)->prev;
		(*tmp1)->next = (*tmp2)->next;
		(*tmp2)->next = *tmp1;
		(*tmp1)->prev = *tmp2;
	}
	else
	{
		if ((*tmp1)->n > (*tmp2)->n)
		{
			(*tmp1)->prev = *tmp2;
			(*tmp2)->next = *tmp1;
			(*tmp1)->next = NULL;
			(*tmp2)->prev = NULL;
			*list = *tmp2;
		}
	}
}
