#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> // para write & read
#include <stdlib.h> // para malloc & free
#include "libft.h"

//declaracao de typedefs para linked lists
typedef struct s_node
{
	int				value;
	int				index;
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

#endif