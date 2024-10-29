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
 * max_heapify - Maintains the max-heap property of a subtree.
 * @__array: Pointer to the array representing the heap.
 * @__size: Number of elements in the array.
 * @__base: Number of elements to consider in the array.
 * @__root: Index of the root of the subtree to be heapified.
 */
void max_heapify(int *__array, size_t __size, size_t __base, size_t __root)
{
	size_t left, right, max;

	left = 2 * __root + 1;
	right = 2 * __root + 2;
	max = __root;

	if (left < __base && __array[left] > __array[max])
		max = left;
	if (right < __base && __array[right] > __array[max])
		max = right;

	if (max != __root)
	{
		swap_ints(__array + __root, __array + max);
		print_array(__array, __size);
		max_heapify(__array, __size, __base, max);
	}
}


/**
 * heap_sort - Sorts an array of integers using the Heap Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; --i)
		max_heapify(array, size, size, i);

	for (i = size - 1; i > 0; --i)
	{
		swap_ints(array, array + i);
		print_array(array, size);
		max_heapify(array, size, i, 0);
	}
}
