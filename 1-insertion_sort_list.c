#include "sort.h"

/**
 * insertion_sort_list - sort a list by insertion
 * @list: the list to sort.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *tmp1, *tmp2;
	int  flag = 1;

	tmp = *list;
	while (flag != 0)
	{
		flag = 0;
		while (tmp)
		{
			if (tmp->next == NULL)
				break;
			if (tmp->n > tmp->next->n)
			{
				tmp1 = tmp;
				tmp2 = tmp->next;
				if (tmp->prev == NULL)
				{
					tmp2->next->prev = tmp1;
					*list = tmp2;
				}
				else if (tmp->next->next == NULL)
					tmp1->prev->next = tmp2;
				else
				{
					tmp2->next->prev = tmp1;
					tmp1->prev->next = tmp2;
				}
				tmp2->prev = tmp1->prev;
				tmp1->next = tmp2->next;
				tmp2->next = tmp1;
				tmp1->prev = tmp2;
				print_list(*list);
				flag = 1;
				tmp = *list;
			}
			else
				tmp = tmp->next;
		}
	}
}
