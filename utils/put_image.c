#include "pacman.h"

struct_control *images(struct_control *stc)
{
	stc->map_img = malloc(sizeof(map_images));
	int pixel_x;
	int pixel_y;

	stc->map_img->empty = mlx_xpm_file_to_image(stc->mlx, "textures/empty.xpm", &pixel_x, &pixel_y);
	stc->map_img->wall = mlx_xpm_file_to_image(stc->mlx, "textures/wall.xpm", &pixel_x, &pixel_y);
	stc->map_img->coin = mlx_xpm_file_to_image(stc->mlx, "textures/coin.xpm", &pixel_x, &pixel_y);
	stc->map_img->chT = mlx_xpm_file_to_image(stc->mlx, "textures/tombT.xpm", &pixel_x, &pixel_y);
	stc->map_img->chB = mlx_xpm_file_to_image(stc->mlx, "textures/tombB.xpm", &pixel_x, &pixel_y);
	stc->map_img->chL = mlx_xpm_file_to_image(stc->mlx, "textures/tombL.xpm", &pixel_x, &pixel_y);
	stc->map_img->chR = mlx_xpm_file_to_image(stc->mlx, "textures/tombR.xpm", &pixel_x, &pixel_y);
	stc->map_img->ball = mlx_xpm_file_to_image(stc->mlx, "textures/ball.xpm", &pixel_x, &pixel_y);
	stc->map_img->portal = mlx_xpm_file_to_image(stc->mlx, "textures/portal.xpm", &pixel_x, &pixel_y);
	stc->map_img->portalCh = mlx_xpm_file_to_image(stc->mlx, "textures/portalCh.xpm", &pixel_x, &pixel_y);
	return (stc);
}

void put_image(struct_control *stc)
{
	int i;
	int j;
	int x;
	int y;
	int coin;
	
	i = -1;
	x = 0;
	y = 0;
	coin = 0;
	step_refresh(stc);
	while (++i < stc->map->mapsize_x)
	{
		j = 0;
		while(stc->map->map[i][j] != '\0')
		{
			put_image2(stc, i, j++, x, y, &coin);
			x += 50;
		}
		x = 0; 
		y += 50;
	}
	stc->ch->is_finish = 0;
	if (coin == 0)
		stc->ch->is_finish = 1;
}

void put_image2(struct_control *stc, int i, int j, int x, int y, int *coin)
{
	if (stc->map->map[i][j] == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->wall, x, y);
	else if (stc->map->map[i][j] == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->empty, x, y);
	else if (stc->map->map[i][j] == 'C')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->coin, x, y);
		*coin += 1;
	}
	else if (stc->map->map[i][j] == 'E')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->portal, x, y);
	else if (stc->map->map[i][j] == 'P' || stc->map->map[i][j] == 'X')
	{
		if (stc->map->map[i][j] == 'X')
			mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->portalCh, x, y);
		else
			mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->chT, x, y);
		stc->ch->i = i;
		stc->ch->j = j;
		stc->ch->x = x;
		stc->ch->y = y;
	}
	x += 50;
	j++;
}

int portal_and_check_img(struct_control *stc, int i, int j, int *step_count)
{
	if (stc->map->map[stc->ch->i][stc->ch->j] == 'X' && stc->map->map[stc->ch->i + i][stc->ch->j + j] != '1')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = 'E';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		map_refresh(stc);
		return (31);
	}
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'E')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'X';
		map_refresh(stc);
		if (stc->ch->is_finish == 1)
		{
			ft_printf("Game Over!");
			exit(0);
		}
		return (31);
	}
	return (0);
}

void map_refresh(struct_control *stc)
{
	mlx_do_sync(stc->mlx);
	mlx_clear_window(stc->mlx, stc->win);
	put_image(stc);
}