NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -Isrc -Ilibft

SRCS = src/start_program.c \
	src/push_swap.c \
	src/parsing/array_int.c \
	src/parsing/verify_errors.c \
	src/sorting/complex.c \
	src/sorting/medium.c \
	src/sorting/simple.c \
	src/sorting/sort_small.c \
	src/operations/pushpop_ops.c \
	src/operations/revrotatestacks_ops.c \
	src/operations/rotatestacks_ops.c \
	src/operations/swap_ops.c \
	src/utils/ft_error.c \
	src/utils/initialize_stacks.c \
	src/utils/normalize_index.c \
	src/utils/print_bench.c

OBJS = $(SRCS:.c=.o) 

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re