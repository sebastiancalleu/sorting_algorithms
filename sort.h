#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


void print_array(const int *, size_t);
void print_list(const listint_t *);
void bubble_sort(int *, size_t);
listint_t *create_listint(const int *, size_t);
void insertion_sort_list(listint_t **);
void selection_sort(int *, size_t);
int sortcheck(int *);
int countnodes(listint_t *);
void nodeswaper(listint_t **, listint_t **, listint_t **, int);
void quick_sort(int *, size_t);
void quicsortrec(int *, int, int, int);
int lomutopart(int *, int, int, int);
void shell_sort(int *, size_t);

#endif
