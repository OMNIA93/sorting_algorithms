#include <stdio.h>

/**
 * swap_int - swaps two elements in an array
 * @a: the first element
 * @b: the second element
 */

void swap(int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * lomuto_partition - partition through an array of integers
 * @array: array of integers
 * @size: the size of the array
 * @l: first index of array
 * @h: last index of array
 *
 * Description: all values must be accurate
 * Return: new index position
 */

int lomuto_partition(int *array, int low, int high) {
int pivot = array[high];
int i = low - 1;

for (int j = low; j <= high - 1; j++) {
if (array[j] <= pivot) {
i++;
swap(&array[i], &array[j]);
}
}

swap(&array[i + 1], &array[high]);
return i + 1;
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

void quick_sort_recursive(int *array, int low, int high) {
if (low < high) {
int partition_index = lomuto_partition(array, low, high);

printf("Partition: ");
for (int i = low; i <= high; i++){ 
printf("%d ", array[i]);
}
printf("\n");

quick_sort_recursive(array, low, partition_index - 1);
quick_sort_recursive(array, partition_index + 1, high);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 *              sort algorithm with the Lomuto partition scheme
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Nothing
 */

void quick_sort(int *array, size_t size) {
if (size < 2) {
return; // Already sorted or empty array
}

quick_sort_recursive(array, 0, size - 1);
}

int main() {
int arr[] = {4, 7, 2, 1, 8, 5, 9, 3, 6};
size_t size = sizeof(arr) / sizeof(arr[0]);

printf("Original Array: ");
for (size_t i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");

quick_sort(arr, size);

printf("Sorted Array: ");
for (size_t i = 0; i < size; i++) {
printf("%d ", arr[i]);
}
printf("\n");

return 0;
}
