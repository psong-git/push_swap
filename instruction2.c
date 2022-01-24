#include "push_swap.h"

void ra(t_linkedlist *stackA)
{
	t_node *last;
	t_node *top1;

	if (stackA->size >= 2)
	{
		top1 = (stackA->head)->next;
		last = getLast(stackA);
		(stackA->head)->next = top1->next;
		(top1->next)->prev = stackA->head;
		last->next = top1;
		top1->prev = last;
		top1->next = stackA->tail;
		(stackA->tail)->prev = top1;
		write(1, "ra\n", 3);
	}
}

void rb(t_linkedlist *stackB)
{
	t_node *top1;
	t_node *last;

	if (stackB->size >= 2)
	{
		top1 = (stackB->head)->next;
		last = getLast(stackB);
		(stackB->head)->next = top1->next;
		(top1->next)->prev = stackB->head;
		last->next = top1;
		top1->prev = last;
		top1->next = stackB->tail;
		(stackB->tail)->prev = top1;
		write(1, "rb\n", 3);
	}
}

void rr(t_linkedlist *stackA, t_linkedlist *stackB)
{
	ra(stackA);
	rb(stackB);
	write(1, "rr\n", 3);
}
