#include "../pacman.h"

void map_refresh(struct_control *stc)
{
	mlx_do_sync(stc->mlx);
	mlx_clear_window(stc->mlx, stc->win);
	put_image(stc);
}

void all(struct_control *stc, int i, int j, int framex, int framey, void *chPos)
{
	static int framexx;
	static int frameyy;

	framexx = 0;
	frameyy = 0;
	stc->map->map[stc->ch->i][stc->ch->j] = '0';
	while (stc->map->map[stc->ch->i + i][stc->ch->j + j] != '1')
	{
		framexx += framex;
		frameyy += framey;
		if ((framexx != 0 && framexx % 50 == 0) || frameyy != 0 && frameyy % 50 == 0)
		{
			stc->ch->i += i;
			stc->ch->j += j;
			stc->map->map[stc->ch->i][stc->ch->j] = '0';
		}
		map_refresh(stc);
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->chT, stc->ch->x + framexx, stc->ch->y + frameyy);
		
	}
	stc->ch->x += framexx;
	stc->ch->y += frameyy;
	map_refresh(stc);
	stc->map->map[stc->ch->i][stc->ch->j] = 'P';
	mlx_put_image_to_window(stc->mlx, stc->win, chPos, stc->ch->x, stc->ch->y);
}

void all2(struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] != '1')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		map_refresh(stc);
	}
}

void key_left(struct_control *stc)
{
	//all(stc, 0, -1, -25, 0, stc->map_img->chL);
	all2(stc, 0, -1);
}

void key_right(struct_control *stc)
{
	//all(stc, 0, 1, 25, 0, stc->map_img->chT);
	all2(stc, 0, 1);
}

void key_up(struct_control *stc)
{
	all2(stc, -1, 0);
}
void key_down(struct_control *stc)
{
	all2(stc, 1, 0);
}

