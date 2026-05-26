#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> // para write & read
#include <stdlib.h> // para malloc & free
#include <stdio.h> // Print so para testes
#include <limits.h>
#include "../../libft/libft.h"

//declaracao de typedefs para linked lists
typedef struct s_node
{
	int				value;
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
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
char	**split_args(char *arg, char c);
int	ft_isdigit(int c);
size_t	ft_strlen(const char *s);
int	num_duplicate(int *arr, int size);
int	num_valid(char *str);
int	verificar_erros(char **args, int size);

#endif