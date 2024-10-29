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
 * merge - Merges two subsequences of a bitonic sequence.
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the subsequence.
 * @__seq: Size of the subsequence to be merged.
 * @__flow: Sorting direction (UP or DOWN).
 */
void merge(int *__array, size_t __size,
			size_t __start, size_t __seq, char __flow)
{
	size_t i, jump = __seq / 2;

	if (__seq > 1)
	{
		for (i = __start; i < __start + jump; i++)
		{
			if ((__flow == UP && __array[i] > __array[i + jump]) ||
			    (__flow == DOWN && __array[i] < __array[i + jump]))
				swap_ints(__array + i, __array + i + jump);
		}
		merge(__array, __size, __start, jump, __flow);
		merge(__array, __size, __start + jump, jump, __flow);
	}
}

/**
 * bitonic_seq - Recursively applies bitonic sequence operations.
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__start: Starting index of the subsequence.
 * @__seq: Size of the subsequence.
 * @__flow: Sorting direction (UP or DOWN).
 */
void bitonic_seq(int *__array, size_t __size,
				size_t __start, size_t __seq, char __flow)
{
	size_t cut = __seq / 2;
	char *str = (__flow == UP) ? "UP" : "DOWN";

	if (__seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", __seq, __size, str);
		print_array(__array + __start, __seq);

		bitonic_seq(__array, __size, __start, cut, UP);
		bitonic_seq(__array, __size, __start + cut, cut, DOWN);
		merge(__array, __size, __start, __seq, __flow);

		printf("Result [%lu/%lu] (%s):\n", __seq, __size, str);
		print_array(__array + __start, __seq);
	}
}


/**
 * bitonic_sort - Sorts an array of integers using the Bitonic Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
