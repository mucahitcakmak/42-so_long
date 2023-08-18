NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	so_long.c \
			include/get_next_line/get_next_line_utils.c	\
			include/get_next_line/get_next_line.c \
			utils/check_map.c \
			utils/character_controller.c \
			include/ft_printf.c \
			utils/put_image.c \
			utils/map_validation.c

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