#include "sort.h"


/**
 * get_max - Finds the maximum element in an array.
 * @__array: Pointer to the array.
 * @__size: Number of elements in the array.
 *
 * Return: Maximum element in the array.
 */
int get_max(int *__array, int __size)
{
	int max, i;

	for (max = __array[0], i = 1; i < __size; i++)
		if (__array[i] > max)
			max = __array[i];
	return (max);
}


/**
 * counting_sort - Sorts an array of integers
 *		using the Counting Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, range, i;

	if (!array || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	range = get_max(array, size) + 1;
	count = malloc(sizeof(int) * range);
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < range; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < range; i++)
		count[i] += count[i - 1];
	print_array(count, range);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
