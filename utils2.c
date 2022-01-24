#include "push_swap.h"

void	number_init(t_num *number)
{
	number->a = 0;
	number->b = 0;
	number->c = 0;
	number->i = 0;
	number->j = 0;
	number->ra_call = 0;
	number->rb_call = 0;
	number->pa_call = 0;
	number->pb_call = 0;
	number->pivot = 0;
}

int	select_pivot(t_all *all, t_linkedlist *stack, int r)
{
	int		i;
	t_node	*current;

	i = 0;
	current = stack->head->next;
	while (i < r)
	{
		all->arr[i] = current->data;
		current = current->next;
		i++;
	}
	bubble_sort(all, r);
	return (all->arr[r / 2]);
}
