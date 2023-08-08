#ifndef PACMAN_H
# define PACMAN_H

# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct map_values{
	int x;
	int y;
	int c;
	int e;
	int p;
	char **map;
}	map_info;

typedef struct images
{
	void *empty;
	void *wall;
	void *coin;
	void *pacmanT;
}	map_images;

typedef struct character
{
	int i;
	int j;
	
}	pacman;


typedef struct total_structs
{
	void *mlx;
	void *win;
	pacman *ch;
	map_images *map_img;
	map_info *map;
}	struct_control;

// pacman.c
struct_control *images(struct_control *stc);
void put_image(struct_control *stc);
int key_code(int keycode, struct_control *stc);

// utils/pacman_controller.c
void key_left(struct_control *stc);
void key_right(struct_control *stc);
void key_up(struct_control *stc);
void key_down(struct_control *stc);

// utils/check_map.c
map_info	*rectangle_control(map_info *map, char *map_name);
void		wall_control(map_info *map);
map_info 	*check_map(char *map_name);


#endif