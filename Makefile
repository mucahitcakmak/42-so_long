NAME 	= so_long

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	so_long.c \
			include/get_next_line/get_next_line_utils.c	\
			include/get_next_line/get_next_line.c \
			include/ft_printf.c \
			utils/bonus.c \
			utils/character_controller.c \
			utils/check_map.c \
			utils/map_validation.c \
			utils/put_image.c \
			utils/put_image2.c


all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(SRCS) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all