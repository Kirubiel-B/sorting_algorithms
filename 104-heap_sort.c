#include "sort.h"

void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_ints - Swap two integer in array.
 * @a: int to swap.
 * @b: int to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * max_heapify - Turn binary tree.
 * @array: array integers representing binary tree.
 * @size: size of array/tree.
 * @base: index of base row tree.
 * @root: root node binary tree.
 */
void max_heapify(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		swap_ints(array + root, array + large);
		print_array(array, size);
		max_heapify(array, size, base, large);
	}
}

/**
 * heap_sort - Sort array integers
 * order using heap sort algorithm.
 * @array: array integers.
 * @size: size of array.
 *
 * Description: Implement sift-down heap sort
 * algorithm.
 * Print array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int y;

	if (array == NULL || size < 2)
		return;

	for (y = (size / 2) - 1; y >= 0; y--)
		max_heapify(array, size, size, y);

	for (y = size - 1; y > 0; y--)
	{
		swap_ints(array, array + y);
		print_array(array, size);
		max_heapify(array, size, y, 0);
	}
}
