#include "push_swap.h"

void two_number(t_linkedlist *stack)
{
	if (stack->head->next->data > stack->head->next->next->data)
		sa(stack);
}

void threeNumber2(t_linkedlist *stack, t_num *var_ptr)
{
	if (var_ptr->a > var_ptr->c && var_ptr->c > var_ptr->b)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (var_ptr->b > var_ptr->c && var_ptr->c > var_ptr->a)
	{
		ra(stack);
		sa(stack);
		rra(stack);
	}
	else if (var_ptr->b > var_ptr->a && var_ptr->a > var_ptr->c)
	{
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
}

void threeNumber(t_linkedlist *stack)
{
	t_num var;

	number_init(&var);
	var.a = stack->head->next->data;
	var.b = stack->head->next->next->data;
	var.c = stack->head->next->next->next->data;
	if (var.a > var.b && var.a < var.c)
		sa(stack);
	else if (var.a > var.b && var.b > var.c)
	{
		sa(stack);
		ra(stack);
		sa(stack);
		rra(stack);
		sa(stack);
	}
	else
		threeNumber2(stack, &var);
}

void fourNumber(t_linkedlist *stackA, t_linkedlist *stackB)
{
	int ra_call;

	ra_call = 0;
	if (is_sorted(stackA, 4) == SORTED)
		return;
	while (getFirst(stackA)->data != min_five(stackA, 4))
	{
		ra(stackA);
		ra_call++;
	}
	pb(stackA, stackB);
	while (ra_call--)
		rra(stackA);
	threeNumber(stackA);
	pa(stackA, stackB);
}

void fiveNumber(t_linkedlist *stackA, t_linkedlist *stackB)
{
	int ra_call;

	ra_call = 0;
	if (is_sorted(stackA, 5) == SORTED)
		return;
	while (getFirst(stackA)->data != min_five(stackA, 5))
	{
		ra(stackA);
		ra_call++;
	}
	pb(stackA, stackB);
	while (ra_call--)
		rra(stackA);
	ra_call = 0;
	while (getFirst(stackA)->data != min_five(stackA, 4))
	{
		ra(stackA);
		ra_call++;
	}
	pb(stackA, stackB);
	while (ra_call--)
		rra(stackA);
	threeNumber(stackA);
	pa(stackA, stackB);
	pa(stackA, stackB);
}
