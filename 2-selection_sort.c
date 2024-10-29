#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers.
 * @__first_int: Pointer to the first integer.
 * @__second_int: Pointer to the second integer.
 */
void swap_ints(int *__first_int, int *__second_int)
{
	*__first_int += *__second_int;
	*__second_int = *__first_int - *__second_int;
	*__first_int -= *__second_int;
}


/**
 * selection_sort - Sorts an array of integers
 *		using the Selection Sort algorithm.
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; ++i)
	{
		min = array + i;
		for (j = i + 1; j < size; ++j)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap_ints(array + i, min);
			print_array(array, size);
		}
	}
}
