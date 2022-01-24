#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	showAll(t_node *head)
{
	t_node	*curNode;

	if (head == NULL)
		return ;
	curNode = head->next;
	while (curNode->next)
	{
		printf("%d\n", curNode->data);
		curNode = curNode->next;
	}
}

int	delOne(t_linkedlist *lst, t_node *del)
{
	t_node	*curNode;
	int		c;

	c = 0;
	if (lst == NULL || del == NULL)
		return (0);
	if (lst->size >= 1)
	{
		c = del->data;
		curNode = del;
		(curNode->prev)->next = curNode->next;
		(curNode->next)->prev = curNode->prev;
		free(del);
		del = NULL;
		(lst->size)--;
	}
	return (c);
}

void	delAll(t_linkedlist *lst)
{
	t_node	*tmp;
	t_node	*curNode;
	int		i;

	i = 0;
	curNode = lst->head->next;
	while (i < lst->size)
	{
		tmp = curNode->next;
		free(curNode);
		curNode = tmp;
		i++;
	}
	free(lst->head);
	free(lst->tail);
	lst->head = NULL;
	lst->tail = NULL;
}

int	delFront(t_linkedlist *lst)
{
	int	c;

	if (lst == NULL)
		return (0);
	c = delOne(lst, (lst->head)->next);
	return (c);
}

void	delLast(t_linkedlist *lst)
{
	if (lst == NULL)
		return ;
	delOne(lst, (lst->tail)->prev);
}
