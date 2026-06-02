NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Isrc -Ilibft

SRCS = $(shell find src -name "*.c" ! -name "main_test.c")

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
	
OBJS_NO_MAIN = $(filter-out src/push_swap.o, $(OBJS))

test: src/main_test.c $(OBJS_NO_MAIN) $(LIBFT)
	$(CC) $(CFLAGS) src/main_test.c $(OBJS_NO_MAIN) $(LIBFT) -o test

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re