#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size);

/* Helper function to perform the Lomuto partition */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size);

/* Helper function to perform the actual Quick Sort */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size);

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
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The final position of the pivot after partitioning
 */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
    int pivot, temp;
    size_t i, j;

    pivot = array[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;

            /* Swap the elements */
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;

            /* Print the array after the swap */
            print_array(array, size);
        }
    }

    /* Swap the pivot with the element at position i + 1 */
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;

    /* Print the array after the swap */
    print_array(array, size);

    return i + 1;
}

/**
 * quick_sort_recursive - Recursive function to perform Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
    if (low < high)
    {
        /* Perform the partition and get the pivot position */
        size_t pivot = lomuto_partition(array, low, high, size);

        /* Recursively sort the left and right partitions */
        if (pivot > 0)
            quick_sort_recursive(array, low, pivot - 1, size);
        quick_sort_recursive(array, pivot + 1, high, size);
    }
}
