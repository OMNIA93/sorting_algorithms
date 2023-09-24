#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm with the Lomuto partition scheme
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursive helper function for the Quick sort algorithm
 *
 * @array: Pointer to the first element of the array
 * @low: Index of the low partition
 * @high: Index of the high partition
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quicksort_recursive(array, low, partition - 1, size);
		quicksort_recursive(array, partition + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for the Quick sort algorithm
 *
 * @array: Pointer to the first element of the array
 * @low: Index of the low partition
 * @high: Index of the high partition
 * @size: Number of elements in the array
 *
 * Return: Index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}

	return (i + 1);
}
