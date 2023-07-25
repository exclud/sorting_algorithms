#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size);

/* Helper function to perform the Lomuto partition */
size_t lomuto_partition(int *array, size_t lo, size_t hi, size_t size);

/* Helper function to perform the actual quick sort recursively */
void quick_sort_recursive(int *array, size_t lo, size_t hi, size_t size);

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be partitioned
 * @lo: Starting index of the partition
 * @hi: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element after partitioning
 */
size_t lomuto_partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot, temp;
	size_t i, j;

	pivot = array[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			/* Swap elements at i and j */
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			/* Print the array after the swap */
			print_array(array, size);

			i++;
		}
	}

	/* Swap the pivot element to its correct position */
	temp = array[i];
	array[i] = array[hi];
	array[hi] = temp;

	/* Print the array after the swap */
	print_array(array, size);

	return (i);
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 *
 * @array: The array to be sorted
 * @lo: Starting index of the partition
 * @hi: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t lo, size_t hi, size_t size)
{
	size_t pivot;

	if (lo < hi)
	{
		pivot = lomuto_partition(array, lo, hi, size);

		if (pivot > 0)
			quick_sort_recursive(array, lo, pivot - 1, size);

		quick_sort_recursive(array, pivot + 1, hi, size);
	}
}
