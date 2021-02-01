#include "sort.h"
#include <stdint.h>

/**
 * bubble_sort - function that bubble sort.
 * @array: array to sort.
 * @size: size of the array.
 */

void bubble_sort(int *array, size_t size)
{

	int tmp, flag = 1;
	unsigned int a;

	while (flag != 0)
	{
		flag = 0;
		for (a = 0; a < size; a++)
		{
			if (a == (size - 1))
				break;
			if (array[a] > array[a + 1])
			{
				tmp = array[a];
				array[a] = array[a + 1];
				array[a + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
	}
}
