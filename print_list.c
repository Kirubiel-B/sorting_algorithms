#include <stdio.h>
#include "sort.h"
/**
 * print_list - function prints a list of integers
 *
 * @list: list to be printed
 */
void print_list(const listint_t *list)
{
	int h;

	h = 0;
	while (list)
	{
		if (h > 0)
			printf(", ");
		printf("%d", list->n);
		++h;
		list = list->next;
	}
	printf("\n");
}
