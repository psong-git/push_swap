#include "push_swap.h"

void exceptional_AB(t_linkedlist *stackA, t_linkedlist *stackB, int r)
{
	if (r <= 1 || r > 5)
		return;
	else if (r == 2)
		two_number(stackA);
	else if (r == 3)
		threeNumber(stackA);
	else if (r == 4)
		fourNumber(stackA, stackB);
	else
		fiveNumber(stackA, stackB);
}

void exceptional_BA(t_linkedlist *stackA, t_linkedlist *stackB, int r)
{
	if (r <= 0 || r > 5)
		return;
	else if (r == 1)
		pa(stackA, stackB);
	else if (r == 2)
	{
		pa(stackA, stackB);
		pa(stackA, stackB);
		two_number(stackA);
	}
}

t_all *all_init(t_linkedlist *stackA, t_linkedlist *stackB)
{
	t_all *tmp;

	tmp = malloc(sizeof(t_all) * 1);
	lstinit(stackA);
	lstinit(stackB);
	tmp->stackA = stackA;
	tmp->stackB = stackB;
	tmp->flag = 0;
	tmp->size = 0;
	return (tmp);
}

void engine(t_all *all)
{
	if (all->stackA->size == 3)
		only_threeNumber(all->stackA);
	else if (all->stackA->size == 4)
		only_fourNumber(all->stackA, all->stackB);
	else if (all->stackA->size == 5)
		only_fiveNumber(all);
	else
		A_to_B(all, all->stackA->size);
}

int main(int ac, char **av)
{
	t_all *all;
	t_linkedlist stackA;
	t_linkedlist stackB;

	if (ac < 2)
		return (FAIL);
	all = all_init(&stackA, &stackB);
	parse_numbers(ac, av, all);
	checkDouble(all, 0, 0, 0);
	is_empty(all);
	if (all->flag >= 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (is_sorted(all->stackA, all->size) == SORTED)
		return (0);
	engine(all);
	delAll(all->stackA);
	delAll(all->stackB);
	free(all);
	return (0);
}
