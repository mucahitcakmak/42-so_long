NAME 	= main

CC 		= gcc

CFLAGS 	= -Wall -Wextra -Werror

SRCS 	=	main.c \
			get_next_line/get_next_line_utils.c	\
			get_next_line/get_next_line.c \
			utils/check_map.c \
			utils/character_controller.c \
			utils/ft_printf.c \
			utils/put_image.c \
			utils/map_validation.c

all: $(NAME)

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(SRCS) -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o:%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all