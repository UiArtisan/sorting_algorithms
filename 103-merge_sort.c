#include "sort.h"


/**
 * merge - Merges two subarrays into a single sorted subarray.
 * @subarr: Pointer to the array to be sorted.
 * @buff: Temporary buffer for merging.
 * @left: Starting index of the left subarray.
 * @middle: Ending index of the left subarray
 *			& starting index of the right subarray.
 * @right: Ending index of the right subarray.
 */
void merge(int *subarr, int *buff, size_t left, size_t middle,
		size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + left, middle - left);

	printf("[right]: ");
	print_array(subarr + middle, right - middle);

	for (i = left, j = middle; i < middle && j < right; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < middle; i++)
		buff[k++] = subarr[i];
	for (; j < right; j++)
		buff[k++] = subarr[j];
	for (i = left, k = 0; i < right; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + left, right - left);
}


/**
 * sort - Recursively sorts subarrays using the Merge Sort algorithm.
 * @subarr: Pointer to the array to be sorted.
 * @buff: Temporary buffer for merging.
 * @left: Starting index of the subarray to be sorted.
 * @right: Ending index of the subarray to be sorted.
 */
void sort(int *subarr, int *buff, size_t left, size_t right)
{
	size_t middle;

	if (right - left < 2)
		return;
	middle = left + (right - left) / 2;
	sort(subarr, buff, left, middle);
	sort(subarr, buff, middle, right);
	merge(subarr, buff, left, middle, right);
}


/**
 * merge_sort - Sorts an array of integers using the Merge Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	sort(array, buff, 0, size);

	free(buff);
}
