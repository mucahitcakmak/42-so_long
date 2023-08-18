#ifndef PACMAN_H
# define PACMAN_H

# include "../include/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

typedef struct map_values{
	int mapsize_x;
	int mapsize_y;
	int c;
	int e;
	int p;
	int m;
	int ch_i;
	int ch_j;
	char **map;
}	map_info;

typedef struct images
{
	void *empty;
	void *wall;
	void *coin;
	void *ch;
	void *ball;
	void *portal;
	void *portalCh;
	void *enemy;
}	map_images;

typedef struct character
{
	int i;
	int j;
	int x;
	int y;
	int is_finish;
}	pacman;

typedef struct	s_point
{
	int			x;
	int			y;
}				fill_point;

typedef struct enemy_move
{
	int i;
	int j;
}	enemy;

typedef struct total_structs
{
	void *mlx;
	void *win;
	pacman *ch;
	map_images *map_img;
	map_info *map;
	enemy *enemy;
}	struct_control;


// main.c
void error_message(char *str);
int key_code(int keycode, struct_control *stc);
int close_game(char *str);

// utils/put_image.c
struct_control *images(struct_control *stc);
void put_image(struct_control *stc);
void put_image2(struct_control *stc, int i, int j, int x, int y, int *coin);
int portal_and_check_img(struct_control *stc, int i, int j);
void map_refresh(struct_control *stc, int i);

// utils/character_controller.c
int all(struct_control *stc, int i, int j, char *ch_image_path);
void key_left(struct_control *stc);
void key_right(struct_control *stc);
void key_up(struct_control *stc);
void key_down(struct_control *stc);

// include/ft_printf.c
void ft_putchar(char c);
void	ft_putnbr(int nb);
void ft_putstr(char *str);
void arg_check(va_list lst, char c);
void ft_printf(const char *str, ...);

// utils/check_map.c
map_info	*rectangle_control(map_info *map, char *map_name);
void	wall_control(map_info *map);
void	check_value(map_info *map, int i, int j);
void map_name_control(char *map_name);
map_info *check_map(char *map_name);


// utils/map_validation.c
void	fill(char **tab, fill_point size, fill_point cur, char to_fill);
void	flood_fill(char **tab, fill_point size, fill_point begin);
char **paint_map(map_info *map);
void is_reachable(map_info *map, char **clone_map);
void map_validation(map_info *map);


// utils/bonus.c
void step_refresh(struct_control *stc, int i);
int enemy_control(struct_control *stc);
static int	ft_nbrlen(int n);
char	*ft_itoa(int n);

// utils/put_image2.c
void put_image3(struct_control *stc, int i, int j, int x, int y);
int enemy_move(struct_control *stc, int i, int j);

#endif