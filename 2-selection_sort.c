#include "sort.h"
/**
 * selection_sort - Sorts the array from the smallest value
 *
 * @array: Array to be sorted
 *
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t index, idx, new;
	int small, swap;

	if (array == NULL || size < 2)
		return;

	for (index = 0; index < size; index++)
	{
		small = array[index];
		new = index;
		for (idx = index + 1; idx < size; idx++)
		{
			if (array[idx] < small)
			{
				small = array[idx];
				new = idx;
			}
		}
		if (new != index)
		{
			swap = array[index];
			array[index] = small;
			array[new] = swap;
			print_array(array, size);
		}
	}
}
