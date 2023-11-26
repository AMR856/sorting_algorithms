#include "sort.h"

void sortedInsertion(listint_t **head, listint_t *);

/**
 * insertion_sort_list - A function to sort a doubly linked list
 * @list: A pointer to a pointer that points to the head
 * of the doubly linked list
 *
 * Return: Nothing (void)
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *mySorted = NULL;
	listint_t *current = *list;
	listint_t *myNext;

	while (current != NULL)
	{
		myNext = current->next;
		current->prev = NULL;
		current->next = NULL;
		sortedInsertion(&mySorted, current);
		current = myNext;
	}
	*list = mySorted;
}

/**
 * sortedInsertion - A function to insert in the sorted list
 * @head: A pointer to a pointer to the head
 * @newNode: A pointer to the new head
 *
 * Return: Nothing (void)
*/

void sortedInsertion(listint_t **head, listint_t *newNode)
{
	listint_t *current;

	if (*head == NULL)
		*head = newNode;
	else if ((*head)->n > newNode->n)
	{
		newNode->next = *head;
		newNode->next->prev = newNode;
		*head = newNode;
	}
	else
	{
		current = *head;
		while (current->next != NULL && current->next->n < newNode->n)
			current = current->next;
		newNode->next = current->next;
		if (current->next != NULL)
			current->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}
