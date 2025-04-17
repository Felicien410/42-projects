NAME = push_swap

LIB_PATH = libft/

LIB = -L libft -lft

SRCS =	main.c \
		ft_split_ps.c \
		add_to_lists_utils.c \
		parsing_args.c \
		stack_operations.c \
		stack_operations2.c \
		stack_operations_combine.c \
		insertion.c \
		lists_fonctions.c \
		less_fives.c \
		insertion_utils.c \
		insertions_utils2.c \
		insertion_one_side.c \
		insertion_other_side.c \

HEADERS =	-I push_swap.h

CC = gcc

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(HEADER) $(OBJS) $(SRCS)
		make -C $(LIB_PATH)
		$(CC) -g $(CFLAGS) $(OBJS) $(LIB) -o $@
		

clean: 
	@rm -f *.out
	@rm -f *.o
	@rm -f $(OBJS)
	make clean -C $(LIB_PATH)


fclean:	clean
	@rm -f $(NAME)
	make fclean -C $(LIB_PATH)


re: fclean all

.PHONY: all clean fclean re