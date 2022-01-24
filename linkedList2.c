#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

t_node	*getSecond(t_linkedlist *lst)
{
	if (lst->size >= 2)
		return ((lst->head)->next->next);
	else
		return (NULL);
}

t_node	*getThird(t_linkedlist *lst)
{
	if (lst->size >= 3)
		return ((lst->head)->next->next->next);
	else
		return (NULL);
}

void	addFront(t_linkedlist *lst, t_node *newNode)
{
	if (lst && newNode)
	{
		add(lst->head, newNode);
		(lst->size)++;
	}
}

void	addBack(t_linkedlist *lst, t_node *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
	if (lst->size == 0)
		add(lst->head, new_node);
	else
		add(getLast(lst), new_node);
	(lst->size)++;
}

int	count(t_linkedlist lst)
{
	return (lst.size);
}
