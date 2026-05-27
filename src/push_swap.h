#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> // para write & read
#include <stdlib.h> // para malloc & free
#include <stdio.h> // Print so para testes
#include <limits.h>
#include "../libft/libft.h"

//declaracao de typedefs para linked lists
typedef struct s_node
{
	int				value;
	size_t			index;
	size_t			position; 
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}	t_stack;

//declaracao de funcoes

char	**split_args(char *arg, char c);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	num_duplicate(int *arr, int j);
int	num_valid(char *str);
int verificar_erros(char **args, int size);
t_node	*get_min_node(t_node *current);
void	pop_stack(t_node *node, t_stack *stack);
void	stack_addtop(t_node *node, t_stack *stack);
t_node	*create_node(int number);
t_stack	*stack_init(int *arraynbr, size_t sizearray);
void	stack_clear(t_stack **stack);
void	pb(t_stack *a, t_stack *b);
void	pa(t_stack *b, t_stack *a);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrb(t_stack *b);
void	rra(t_stack *a);
void	rrr(t_stack *a, t_stack *b);

#endif