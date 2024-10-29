#include "sort.h"

/**
 * swap_ints - Swaps the values of two integers.
 * @__first_int: Pointer to the first integer.
 * @__second_int: Pointer to the second integer.
 */
void swap_ints(int *__first_int, int *__second_int)
{
	if (*__first_int == *__second_int)
		return;
	*__first_int ^= *__second_int;
	*__second_int ^= *__first_int;
	*__first_int ^= *__second_int;
}


/**
 * partition - Partitions an array and selects a pivot using the Hoare scheme.
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the subarray.
 * @__end: Ending index of the subarray.
 *
 * Return: Index of the partition.
 */
int partition(int *__array, size_t __size, int __start, int __end)
{
	int pivot, boundary, idx;

	pivot = __array[__end];
	for (boundary = __start - 1, idx = __end + 1; boundary < idx;)
	{
		do {
			boundary++;
		} while (__array[boundary] < pivot);
		do {
			idx--;
		} while (__array[idx] > pivot);

		if (boundary < idx)
		{
			swap_ints(__array + boundary, __array + idx);
			print_array(__array, __size);
		}
	}

	return (boundary);
}


/**
 * sort - Recursively sorts a subarray using the Quick Sort algorithm.
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the subarray.
 * @__end: Ending index of the subarray.
 */
void sort(int *__array, size_t __size, int __start, int __end)
{
	int boundary;

	if (__start >= __end)
		return;
	boundary = partition(__array, __size, __start, __end);
	sort(__array, __size, __start, boundary - 1);
	sort(__array, __size, boundary, __end);
}


/**
 * quick_sort_hoare - Sorts an array of integers
 *		using the Quick Sort algorithm (Hoare partition scheme).
 *
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, size, 0, size - 1);
}
