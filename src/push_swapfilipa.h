#ifndef PUSH_SWAPFILIPA_H
# define PUSH_SWAPFILIPA_H

#include <unistd.h> // para write & read
#include <stdlib.h> // para malloc & free
#include "libft.h"

//declaracao de typedefs para linked lists
typedef struct s_node
{
	int				value;
	int				index;
	int				position;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node; 

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	size_t	size;
}	t_stack;

float	normalize_index(t_stack *a);
t_node	*get_min_node(t_node *current); //NOVO
void	pop_stack(t_node *node, t_stack *stack); //NOVO
void	stack_addtop(t_node *node, t_stack *stack); //NOVO
void	pb(t_stack *a, t_stack *b); //NOVO
void	pa(t_stack *b, t_stack *a); //NOVO
void	ra(t_stack *a); //NOVO
void	rb(t_stack *b); //NOVO
void	rr(t_stack *a, t_stack *b); //NOVO
void	rrb(t_stack *b); //NOVO
void	rra(t_stack *a); //NOVO
void	rrr(t_stack *a, t_stack *b); //NOVO

#endif