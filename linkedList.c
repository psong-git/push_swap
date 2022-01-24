#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	lstinit(t_linkedlist *lst)
{
	lst->head = malloc(sizeof(t_node));
	if (!lst->head)
		return ;
	lst->tail = malloc(sizeof(t_node));
	if (!lst->tail)
		return ;
	lst->head->prev = NULL;
	lst->head->next = lst->tail;
	lst->tail->prev = lst->head;
	lst->tail->next = NULL;
	lst->size = 0;
}

t_node	*lstnew(int data)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (0);
	list->data = data;
	list->prev = NULL;
	list->next = NULL;
	return (list);
}

void	add(t_node *currNode, t_node *newNode)
{
	newNode->next = currNode->next;
	(currNode->next)->prev = newNode;
	newNode->prev = currNode;
	currNode->next = newNode;
}

t_node	*getLast(t_linkedlist *lst)
{
	if (lst->size >= 1)
		return ((lst->tail)->prev);
	else
		return (NULL);
}

t_node	*getFirst(t_linkedlist *lst)
{
	if (lst->size >= 1)
		return ((lst->head)->next);
	else
		return (NULL);
}
