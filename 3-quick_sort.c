#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers.
 * @__array: The array to be printed.
 * @__size: Number of elements in @array.
 * @__first_int: Pointer to the first integer.
 * @__second_int: Pointer to the second integer.
 */
void swap_ints(int *__array, size_t __size,
				int *__first_int, int *__second_int)
{
	if (*__first_int != *__second_int)
	{
		*__first_int += *__second_int;
		*__second_int = *__first_int - *__second_int;
		*__first_int -= *__second_int;
		print_array(__array, __size);
	}
}


/**
 * partition - Partitions an array using the Lomuto partition scheme.
 * @__array: Pointer to the array to be partitioned.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the partition.
 * @__end: Ending index of the partition.
 *
 * Return: Index of the pivot element after partition.
 */
int partition(int *__array, size_t __size, int __start, int __end)
{
	int pivot = __array[__end], boundary = __start - 1, idx;

	for (idx = __start; idx <= __end; ++idx)
		if (__array[idx] <= pivot)
			swap_ints(__array, __size, __array + idx, &__array[++boundary]);
	return (boundary);
}


/**
 * lomuto_sort - Sorts an array using the Lomuto partition scheme.
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the array.
 * @__end: Ending index of the array.
 */
void lomuto_sort(int *__array, size_t __size, int __start, int __end)
{
	int boundary;

	if (__start >= __end)
		return;
	boundary = partition(__array, __size, __start, __end);
	lomuto_sort(__array, __size, __start, boundary - 1);
	lomuto_sort(__array, __size, boundary + 1, __end);
}


/**
 * quick_sort - Sorts an array of integers using the Quick Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
