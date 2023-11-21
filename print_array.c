#include <stdlib.h>
#include <stdio.h>
/**
 * print_array - function prints an array of integers
 *
 * @array: array to be printed
 * @size: Num of elements in @array
 */
void print_array(const int *array, size_t size)
{
	size_t w;

	w = 0;
	while (array && w < size)
	{
		if (w > 0)
			printf(", ");
		printf("%d", array[w]);
		++w;
	}
	printf("\n");
}
