#include "push_swap.h"

void rra(t_linkedlist *stackA)
{
	t_node *top1;
	t_node *last;

	if (stackA->size >= 2)
	{
		top1 = (stackA->head)->next;
		last = getLast(stackA);
		(last->prev)->next = stackA->tail;
		(stackA->tail)->prev = last->prev;
		(stackA->head)->next = last;
		last->prev = stackA->head;
		last->next = top1;
		top1->prev = last;
		write(1, "rra\n", 4);
	}
}

void rrb(t_linkedlist *stackB)
{
	t_node *top1;
	t_node *last;

	if (stackB->size >= 2)
	{
		top1 = (stackB->head)->next;
		last = getLast(stackB);
		(last->prev)->next = stackB->tail;
		(stackB->tail)->prev = last->prev;
		(stackB->head)->next = last;
		last->prev = stackB->head;
		last->next = top1;
		top1->prev = last;
		write(1, "rrb\n", 4);
	}
}

void rrr(t_linkedlist *stackA, t_linkedlist *stackB)
{
	rra(stackA);
	rrb(stackB);
	write(1, "rrr\n", 4);
}

void pa(t_linkedlist *stackA, t_linkedlist *stackB)
{
	int c;

	if (stackB->size >= 1)
	{
		c = delFront(stackB);
		addFront(stackA, lstnew(c));
		write(1, "pa\n", 3);
	}
}

void pb(t_linkedlist *stackA, t_linkedlist *stackB)
{
	int c;

	if (stackA->size >= 1)
	{
		c = delFront(stackA);
		addFront(stackB, lstnew(c));
		write(1, "pb\n", 3);
	}
}
