#include "sort.h"
/**
 * swap - swaps two indices of an array
 * @x: variable
 * @y: variable
 * Return: void
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *y;
	*y = *x;
	*x = temp;
}
/**
 * quick_sort - takes in array to be sorted and size
 * and calls quick_sort_recursion for iteration
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quicksort_recursion(array, size, 0, size - 1);
}
/**
 * quicksort_recursion - A recursive call for proper swaping
 * @array: array to be swapped
 * @low: lower bound
 * @size: size of array
 * @high: upper bound
 * Return: void
 */
void quicksort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quicksort_recursion(array, size, low, pivot_index - 1);
		quicksort_recursion(array, size, pivot_index + 1, high);
	}
}
/**
 * partition - partitions the array int sub arrays
 * @array: array to be partitioned
 * @low: lower bound
 * @high: upper bound
 * @size: size of array
 * Return: new pivot_index
 */
int partition(int *array, size_t size, int low, int high)
{
	int *pivot, index, idx;

	/*index = low;*/
	pivot = array + high;

	for (index = idx = low; idx < high; idx++)
	{
		if (array[idx] < *pivot)
		{
			if (index < idx)
			{
				swap(array + idx, array + index);
				print_array(array, size);
			}
			index++;
		}
	}
	if (array[index] > *pivot)
	{
		swap(array + index, pivot);
		print_array(array, size);
	}
	return (index);
}
