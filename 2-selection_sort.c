#include "sort.h"
#include <limits.h>
#include <stdio.h>

/**
 * selection_sort - sort by selection.
 * @array: the array.
 * @size: the size of the array.
 */

void selection_sort(int *array, size_t size)
{
	int tmp, min = INT_MAX;
	unsigned int a, b;

	for (b = 0; b < size; b++)
	{
		for (a = b; a < size; a++)
		{
			if (array[a] < min)
			{
				min = array[a];
				tmp = a;
			}
		}
		if (array[tmp] != array[b])
		{
			array[tmp] = array[b];
			array[b] = min;
			print_array(array, size);
		}
		if (sortcheck(array) == 0)
			break;
		min = INT_MAX;
	}
}

/**
 * sortcheck - check if an array is sort
 * @arr: the array.
 * Return: 1 if not sorted, 0 if sort.
 */

int sortcheck(int *arr)
{
	int a, b;

	for (a = 0; arr[a]; a++)
	{
		for (b = a; arr[b]; b++)
		{
			if (arr[a] > arr[b])
				return (1);
		}
	}
	return (0);
}
