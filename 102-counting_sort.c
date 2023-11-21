#include "sort.h"

/**
 * get_max - maximum value array integers.
 * @array: array integers.
 * @size: size array.
 *
 * Return: maximum integer array.
 */
int get_max(int *array, int size)
{
	int max, q;

	for (max = array[0], q = 1; q < size; q++)
	{
		if (array[q] > max)
			max = array[q];
	}

	return (max);
}

/**
 * counting_sort - Sort array integers ascending order
 * using counting sort algorithm.
 * @array: Array integer.
 * @size: size of array.
 *
 * Description: counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max, q;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (q = 0; q < (max + 1); q++)
		count[q] = 0;
	for (q = 0; q < (int)size; q++)
		count[array[q]] += 1;
	for (q = 0; q < (max + 1); q++)
		count[q] += count[q - 1];
	print_array(count, max + 1);

	for (q = 0; q < (int)size; q++)
	{
		sorted[count[array[q]] - 1] = array[q];
		count[array[q]] -= 1;
	}

	for (q = 0; q < (int)size; q++)
		array[q] = sorted[q];

	free(sorted);
	free(count);
}
