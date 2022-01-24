#include "push_swap.h"

void	only_threeNumber(t_linkedlist *stackA)
{
	t_num	var;

	var.a = stackA->head->next->data;
	var.b = stackA->head->next->next->data;
	var.c = stackA->head->next->next->next->data;
	if (var.a > var.b && var.a < var.c)
		sa(stackA);
	else if (var.a > var.b && var.b > var.c)
	{
		sa(stackA);
		rra(stackA);
	}
	else if (var.a > var.c && var.c > var.b)
		ra(stackA);
	else if (var.b > var.c && var.c > var.a)
	{
		sa(stackA);
		ra(stackA);
	}
	else if (var.b > var.a && var.a > var.c)
		rra(stackA);
}

void	only_fourNumber(t_linkedlist *stackA, t_linkedlist *stackB)
{
	while (getFirst(stackA)->data != min_five(stackA, 4))
		ra(stackA);
	pb(stackA, stackB);
	threeNumber(stackA);
	pa(stackA, stackB);
}

void	only_fiveNumber(t_all *all)
{
	int		i;
	int		c;
	t_num	tmp;

	i = 0;
	find_two_low_nb(all, &tmp);
	while (i < 5)
	{
		c = getFirst(all->stackA)->data;
		if (c == tmp.a || c == tmp.b)
			pb(all->stackA, all->stackB);
		else
			ra(all->stackA);
		if (all->stackB->size == 2)
			break ;
		i++;
	}
	only_threeNumber(all->stackA);
	pa(all->stackA, all->stackB);
	pa(all->stackA, all->stackB);
	two_number(all->stackA);
}

void	find_two_low_nb(t_all *all, t_num *tmp)
{
	int		i;
	t_node	*current;

	i = 0;
	current = all->stackA->head->next;
	while (i < 5)
	{
		all->arr[i] = current->data;
		current = current->next;
		i++;
	}
	bubble_sort(all, 5);
	tmp->a = all->arr[0];
	tmp->b = all->arr[1];
}
