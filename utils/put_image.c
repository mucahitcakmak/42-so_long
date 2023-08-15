#include "../pacman.h"

struct_control *images(struct_control *stc)
{
	stc->map_img = malloc(sizeof(map_images));
	int pixel_x;
	int pixel_y;

	stc->map_img->empty = mlx_xpm_file_to_image(stc->mlx, "img/empty.xpm", &pixel_x, &pixel_y);
	stc->map_img->wall = mlx_xpm_file_to_image(stc->mlx, "img/wall.xpm", &pixel_x, &pixel_y);
	stc->map_img->coin = mlx_xpm_file_to_image(stc->mlx, "img/coin.xpm", &pixel_x, &pixel_y);
	stc->map_img->chT = mlx_xpm_file_to_image(stc->mlx, "img/tombT.xpm", &pixel_x, &pixel_y);
	stc->map_img->chB = mlx_xpm_file_to_image(stc->mlx, "img/tombB.xpm", &pixel_x, &pixel_y);
	stc->map_img->chL = mlx_xpm_file_to_image(stc->mlx, "img/tombL.xpm", &pixel_x, &pixel_y);
	stc->map_img->chR = mlx_xpm_file_to_image(stc->mlx, "img/tombR.xpm", &pixel_x, &pixel_y);
	stc->map_img->ball = mlx_xpm_file_to_image(stc->mlx, "img/ball.xpm", &pixel_x, &pixel_y);
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
	while (i < stc->map->mapsize_x)
	{
		j = 0;
		while(stc->map->map[i][j] != '\0')
		{
			put_image2(stc, i, j, x, y);
			x += 50;
			j++;
		}
		x = 0; 
		y += 50;
		i++;
	}
}

void put_image2(struct_control *stc, int i, int j, int x, int y)
{

	if (stc->map->map[i][j] == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->wall, x, y);
	else if (stc->map->map[i][j] == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->empty, x, y);
	else if (stc->map->map[i][j] == 'C')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->coin, x, y);
	else if (stc->map->map[i][j] == 'P')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->chT, x, y);
		stc->ch->i = i;
		stc->ch->j = j;
		stc->ch->x = x;
		stc->ch->y = y;
	}
	// else if (stc->map->map[i][j] == 'E')
	// 	mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->chT, x, y);
	x += 50;
	j++;
	
}
