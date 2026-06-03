#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> // para write & read
#include <stdlib.h> // para malloc & free
#include <stdio.h> // Printf so para testes
#include <limits.h>
#include "../libft/libft.h"


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
	struct s_node	*head;
	struct s_node	*tail;
	size_t			size;
}	t_stack;

typedef struct s_flags
{
	int		has_flags;
	int		strategy;
	int		has_bench;
}	t_flags;

typedef enum e_strategy
{
	start_simple,
	start_medium,
	start_complex,
	start_adaptive
}t_strategy;

typedef enum e_complexity
{
	o1,
	on2,
	onn,
	onlogn,
}t_complexity;

typedef struct s_bench
{
    int		pa;
    int		pb;
    int		sa;
    int		sb;
    int		ss;
    int		ra;
    int		rb;
    int		rr;
    int		rra;
    int		rrb;
    int		rrr;
	float	disorder;
	int 	complexity;
}   t_bench;


//struct mae com tudo
typedef struct s_data
{
    t_stack     *stack_a;
    t_stack     *stack_b;
    t_flags     flags;
	t_bench		bench;
}   t_data;

//declaracao de funcoes

int		*splitfirst(int argc, char **argv, int *size);
int		count_args(char **res);
int		num_valid(char *str);
int 	verificar_erros(char **args, int size);
int	jump_flags(char *argv);
t_flags verificar_flags(int argc, char **argv);
int		numbers_verifications(char **res, int *numbers, int *index);
int		ft_strcmp(const char *s1, const char *s2);
t_node	*get_min_node(t_node *current);
void	pop_stack(t_node *node, t_stack *stack);
void	stack_addtop(t_node *node, t_stack *stack);
t_node	*create_node(int number);
t_stack	*stack_init(int *arraynbr, int sizearray);
void	stack_clear(t_stack **stack);
void    start_program(t_data *data);
void	normalize_index(t_stack *a);
float	compute_disorder(t_stack *a);
void	update_positions(t_stack *stack);
void	print_bench(t_data *data); // tornar static?
void ft_error (void);
int	count_args(char **res);
int	numbers_verifications(char **res, int *numbers, int *index);
int	ft_strcmp(const char *s1, const char *s2);
char	**split_args(char *arg, char c);
void	free_spl(char **split);
void    free_and_exit(char **res, int *numbers);
//operations
void	pb(t_data *data);
void	pa(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rrb(t_data *data);
void	rra(t_data *data);
void	rrr(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

//algorithms
void	simple(t_data *data);
void	complex(t_data *data);
void    sort_small(t_data *data);
void    medium(t_data *data);

# endif