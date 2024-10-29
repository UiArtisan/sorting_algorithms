#include "sort.h"

/**
 * get_max_gap - Computes the maximum gap for the Shell Sort algorithm.
 * @__size: Number of elements in the array.
 *
 * Return: Maximum gap.
 */
size_t get_max_gap(size_t __size)
{
	size_t gap = 1;

	while (gap < __size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}


/**
 * shell_sort - Sorts an array of integers using the Shell Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array || size < 2)
	return;

	for (gap = get_max_gap(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; ++i)
		{
			temp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}

}
