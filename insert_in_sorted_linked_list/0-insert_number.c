#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts node into sorted SLL
 * @head: Double pointer to head of list
 * @number: Value for new node
 *
 * Return: Pointer to new node or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *cursor1 = *head, *cursor2 = *head;
	listint_t *new = NULL, *aux = NULL;

	if (!head)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = number;
	if (!*head)
	{
		*head = new;
		return (new);
	}

	if (cursor1->n > number)
	{
		*head = new;
		new->next = cursor1;
		return (new);
	}
	cursor2 = cursor1->next;
	while (cursor2 && number > cursor2->n)
	{
		cursor1 = cursor2;
		cursor2 = cursor2->next;
	}
	if (!cursor2)
	{
		cursor1->next = new;
		return (new);
	}
	cursor1->next = new;
	new->next = cursor2;
	return (new);
}
