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
 * radix_counting_sort - Performs counting sort
 *		on a single digit place for Radix Sort.
 *
 * @__array: Pointer to the array to be sorted.
 * @__size: Number of elements in the array.
 * @__sig: The current significant digit place.
 * @__buff: Temporary buffer for sorting.
 */
void radix_counting_sort(int *__array, size_t __size, int __sig, int *__buff)
{
	int count[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < __size; ++i)
		count[(__array[i] / __sig) % 10] += 1;
	for (i = 0; i < 10; ++i)
		count[i] += count[i - 1];
	for (i = __size - 1; (int)i >= 0; --i)
	{
		__buff[count[(__array[i] / __sig) % 10] - 1] = __array[i];
		count[(__array[i] / __sig) % 10] -= 1;
	}
	for (i = 0; i < __size; ++i)
		__array[i] = __buff[i];
}


/**
 * radix_sort - Sorts an array of integers using the Radix Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (!array || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
