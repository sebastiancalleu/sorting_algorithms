#include "sort.h"

/**
 * shell_sort - sort an array.
 * @array: the array.
 * @size: size of the array.
 */

void shell_sort(int *array, size_t size)
{
	size_t interval = 1, a;
	int tmp1, flag;

	if (array == NULL || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval >= 1)
	{
		flag = 0;
		for (a = 0; a + interval < size; a++)
		{
			if (array[a] > array[a + interval])
			{
				tmp1 = array[a];
				array[a] = array[a + interval];
				array[a + interval] = tmp1;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			print_array(array, size);
			interval = (interval - 1) / 3;
		}
	}
}
