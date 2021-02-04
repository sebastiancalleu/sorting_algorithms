#include "sort.h"

/**
 * quick_sort - function to sort an array.
 * @array: the array.
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 2)
		quicsortrec(array, size,  0, (size - 1));
	else
		return;
}

/**
 * quicsortrec - function to use recursion in partitions.
 * @size: size of the array.
 * @array: the array.
 * @first_elem: the first element of the array.
 * @last_elem: the last element of the array.
 */

void quicsortrec(int *array, int size, int first_elem, int last_elem)
{
	int pos;

	if (first_elem < last_elem)
	{
		pos = lomutopart(array, first_elem, last_elem, size);
		quicsortrec(array, size, first_elem, pos - 1);
		quicsortrec(array, size, pos + 1, last_elem);
	}
}

/**
 * lomutopart - function that implement lomuto partition.
 * @array: the array.
 * @first_elem: the first element of the array.
 * @last_elem: the last element of the array.
 * @size: the size of the array.
 * Return: position to do the partition.
 */

int lomutopart(int *array, int first_elem, int last_elem, int size)
{
	int pivot = array[last_elem], tmp1, i = first_elem, j = first_elem;

	while (j <= last_elem)
	{
		if (array[j] < pivot || j == last_elem)
		{
			if (array[j] != array[i])
			{
				tmp1 = array[i];
				array[i] = array[j];
				array[j] = tmp1;
				print_array(array, size);
			}
			if (j != last_elem)
				i++;
		}
		j++;
	}
	return (i);
}
