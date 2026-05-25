#include "push_swap.h"

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node1;

	node1 = NULL;
	if (!a)
		return ;
	else
		node1 = a->head;
// funcao que retira o node do topo de a:
	a->head = a->head->next;
// funcao que coloca o node no topo de b:
	if (!b) 
		lstaddnew(node1, &b);
	else
		lstaddfront(node1, &b);
}