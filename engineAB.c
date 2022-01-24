#include "push_swap.h"

void quick_sort_AB(t_all *all, int r, t_num *var_ptr)
{
	int i;

	i = 0;
	while (i < r)
	{
		if (getFirst(all->stackA)->data > var_ptr->pivot)
		{
			ra(all->stackA);
			var_ptr->ra_call++;
		}
		else
		{
			pb(all->stackA, all->stackB);
			var_ptr->pb_call++;
		}
		i++;
	}
}

void quick_sort_BA(t_all *all, int r, t_num *var_ptr)
{
	int i;

	i = 0;
	while (i < r)
	{
		if (getFirst(all->stackB)->data < var_ptr->pivot)
		{
			rb(all->stackB);
			var_ptr->rb_call++;
		}
		else
		{
			pa(all->stackA, all->stackB);
			var_ptr->pa_call++;
		}
		i++;
	}
}

void A_to_B(t_all *all, int r)
{
	t_num var;

	number_init(&var);
	if (r <= 5)
	{
		exceptional_AB(all->stackA, all->stackB, r);
		return;
	}
	var.pivot = select_pivot(all, all->stackA, r);
	quick_sort_AB(all, r, &var);
	while (var.i < var.ra_call)
	{
		rra(all->stackA);
		var.i++;
	}
	A_to_B(all, var.ra_call);
	B_to_A(all, var.pb_call);
}

void B_to_A(t_all *all, int r)
{
	t_num var;

	number_init(&var);
	if (r <= 2)
	{
		exceptional_BA(all->stackA, all->stackB, r);
		return;
	}
	var.pivot = select_pivot(all, all->stackB, r);
	quick_sort_BA(all, r, &var);
	while (var.i < var.rb_call)
	{
		rrb(all->stackB);
		var.i++;
	}
	A_to_B(all, var.pa_call);
	B_to_A(all, var.rb_call);
}
