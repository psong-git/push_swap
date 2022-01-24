#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max_five(t_linkedlist *stack)
{
	int		c;
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack->head->next;
	c = curr->data;
	while (i < stack->size - 1)
	{
		c = max(c, curr->next->data);
		curr = curr->next;
		i++;
	}
	return (c);
}

int	min_five(t_linkedlist *stack, int r)
{
	int		c;
	int		i;
	t_node	*curr;

	i = 0;
	curr = stack->head->next;
	c = curr->data;
	while (i < r - 1)
	{
		c = min(c, curr->next->data);
		curr = curr->next;
		i++;
	}
	return (c);
}

void	bubble_sort(t_all *all, int r)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < r - 1)
	{
		j = 0;
		while (j < r - 1)
		{
			if (all->arr[j] > all->arr[j + 1])
			{
				tmp = all->arr[j];
				all->arr[j] = all->arr[j + 1];
				all->arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
