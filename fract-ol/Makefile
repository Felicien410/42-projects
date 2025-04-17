NAME = fractol

OBJS = ${SRCS:.c=.o}

SRCS =	events.c \
		julia.c \
		main.c \
		mandelbrot.c \
		utils.c \
		utils2.c \
		utils3.c \
		simplegroove.c \
		brain.c 

HEADERS =	-I ./Includes/fractol.h

$(NAME):
	gcc -Wall -Werror -Wextra -O3 -lmlx -framework Appkit -framework OpenGL $(HEADERS) -o $(NAME) $(SRCS)

all:	$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean bonus
