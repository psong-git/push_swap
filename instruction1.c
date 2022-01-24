#include "push_swap.h"

void sa(t_linkedlist *stackA)
{
	t_node *top1;
	t_node *top2;

	if (stackA->size >= 2)
	{
		top1 = (stackA->head)->next;
		top2 = top1->next;
		top1->next = top2->next;
		top2->next->prev = top1;
		top2->next = top1;
		top1->prev = top2;
		stackA->head->next = top2;
		top2->prev = stackA->head;
		write(1, "sa\n", 3);
	}
}

void sb(t_linkedlist *stackB)
{
	t_node *top1;
	t_node *top2;

	if (stackB->size >= 2)
	{
		top1 = (stackB->head)->next;
		top2 = top1->next;
		top1->next = top2->next;
		top2->next->prev = top1;
		top2->next = top1;
		top1->prev = top2;
		stackB->head->next = top2;
		top2->prev = stackB->head;
		write(1, "sb\n", 3);
	}
}

void ss(t_linkedlist *stackA, t_linkedlist *stackB)
{
	sa(stackA);
	sb(stackB);
	write(1, "ss\n", 3);
}
