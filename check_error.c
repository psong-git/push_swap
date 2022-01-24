#include "push_swap.h"

void	error_type(int flag)
{
	if (flag == 1)
		write(1, "stack over flow\n", 30);
	else if (flag == 2)
		write(1, "has same numbers\n", 30);
	else if (flag == 3)
		write(1, "is already sorted\n", 30);
	else if (flag == 4)
		write(1, "is not digit\n", 30);
	else if (flag == 5)
		write(1, "stack is empty\n", 30);
	else
		write(1, "lots of errors\n", 30);
}

void	checkDouble(t_all *all, int i, int j, int c)
{
	t_node	*curr;

	curr = all->stackA->head->next;
	while (j < all->stackA->size)
	{
		all->arr[j] = curr->data;
		all->size++;
		curr = curr->next;
		j++;
	}
	while (i < all->size)
	{
		j = i + 1;
		while (j < all->size)
		{
			if (all->arr[i] == all->arr[j])
				c++;
			j++;
		}
		i++;
	}
	if (c >= 1)
		all->flag = 2;
}

int	parse_numbers(int ac, char **av, t_all *all)
{
	char	**s2;
	int		i;
	int		j;

	i = 1;
	while (i < ac)
	{
		s2 = ft_split(av[i], ' ');
		j = 0;
		while (s2[j])
		{
			if (!ft_isdigit(s2[j]))
			{
				all->flag = 4;
				return (FAIL);
			}
			addBack(all->stackA, lstnew(ft_atoi(s2[j], &all->flag)));
			j++;
		}
		i++;
		ft_malloc_error(s2);
	}
	return (SUCCESS);
}

int	is_empty(t_all *all)
{
	if (all->stackA->size == 0)
	{
		all->flag = 5;
		return (FALSE);
	}
	return (TRUE);
}

int	is_sorted(t_linkedlist *stack, int r)
{
	int		i;
	t_node	*curr;
	t_node	*after;

	i = 0;
	curr = stack->head->next;
	after = stack->head->next->next;
	while (i < r - 1)
	{
		if (curr->data > after->data)
			return (NOT_SORTED);
		curr = after;
		after = after->next;
		i++;
	}
	return (SORTED);
}
