#include "pacman.h"

struct_control *images(struct_control *stc)
{
	stc->map_img = malloc(sizeof(map_images));
	int pixel_x;
	int pixel_y;
	stc->map_img->empty = mlx_xpm_file_to_image(stc->mlx, "img/empty.xpm", &pixel_x, &pixel_y);
	stc->map_img->wall = mlx_xpm_file_to_image(stc->mlx, "img/wall.xpm", &pixel_x, &pixel_y);
	stc->map_img->coin = mlx_xpm_file_to_image(stc->mlx, "img/coin.xpm", &pixel_x, &pixel_y);
	stc->map_img->pacmanT = mlx_xpm_file_to_image(stc->mlx, "img/pacmanR.xpm", &pixel_x, &pixel_y);
	return (stc);
}
void put_image(struct_control *stc)
{
	int i;
	int j;
	int x;
	int y;
	
	i = 0;
	x = 0;
	y = 0;
	while (i < stc->map->x)
	{
		j = 0;
		while(stc->map->map[i][j] != '\0')
		{
			if (stc->map->map[i][j] == '1')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->wall, x, y);
			else if (stc->map->map[i][j] == '0')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->empty, x, y);
			else if (stc->map->map[i][j] == 'C')
				mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->coin, x, y);
			else if (stc->map->map[i][j] == 'P')
			{
				mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->pacmanT, x, y);
				stc->ch = malloc(sizeof(int) * 2);
				stc->ch->i = i;
				stc->ch->j = j;
			}
			x += 50;
			j++;
		}
		x = 0; 
		y += 50;
		i++;
	}
}
int key_code(int keycode, struct_control *stc)
{
	if (keycode == 0)
		key_left(stc);
	else if (keycode == 1)
		key_down(stc);
	else if (keycode == 2)
		key_right(stc);
	else if (keycode == 13)
		key_up(stc);
	return (0);
}
int main(int argc, char *argv[])
{
	struct_control *stc;

	stc = malloc(sizeof(struct_control));
	stc->mlx = mlx_init();
	stc->map = check_map(argv[1]);
    stc->win = mlx_new_window(stc->mlx, stc->map->y * 50, stc->map->x * 50, "Pacman");
	stc = images(stc);
	put_image(stc);

	mlx_key_hook(stc->win, key_code, stc);
    mlx_loop(stc->mlx);
    return 0;
}
