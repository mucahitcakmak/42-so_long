NAME 	= pacman

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	pacman.c \
			get_next_line/get_next_line_utils.c	\
			get_next_line/get_next_line.c \
			utils/check_map.c \
			utils/pacman_controller.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all