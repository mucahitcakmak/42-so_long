#include "../pacman.h"


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

int all2(struct_control *stc, int i, int j)
{
	static int step_count = 1;

	if (portal_and_check_img(stc, i, j) == 2)
		return (0);
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' || stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		ft_printf("Step: %d\n", step_count++);
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		map_refresh(stc);
	}
	return (0);
}

void key_left(struct_control *stc)
{
	all2(stc, 0, -1);
}

void key_right(struct_control *stc)
{
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

