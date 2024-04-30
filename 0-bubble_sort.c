#include "sort.h"
/**
 * bubble_sort - Sorts an array or a list ordely
 * by bubbling the largeest value to the bottom of
 * the list or array
 *
 * @array: Array to be sorted
 *
 * @size: Size of array
 *
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t index, idx, swap;

	for (index = 0; index < size; index++)
	{
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				swap = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
