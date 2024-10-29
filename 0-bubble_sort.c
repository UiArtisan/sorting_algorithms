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
 * bubble_sort - Sorts an array of integers using the Bubble Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t idx, len = size;
	bool is_sorted = false;

	if (!array || size < 2)
		return;

	while (!is_sorted)
	{
		is_sorted = true;
		for (idx = 0; idx < len - 1; ++idx)
		{
			if (array[idx] > array[idx + 1])
			{
				swap_ints(array + idx, array + idx + 1);
				print_array(array, size);
				is_sorted = false;
			}
		}
		--len;
	}
}
