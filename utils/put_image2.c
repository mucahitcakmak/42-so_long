#include "pacman.h"

void put_image3(struct_control *stc, int i, int j, int x, int y)
{
	if (stc->map->map[i][j] == 'M')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->enemy, x, y);
		stc->enemy->i = i;
		stc->enemy->j = j;
	}
}

int enemy_move(struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != '1')
	{
		stc->map->map[stc->enemy->i + i][stc->enemy->j + j] = 'M';
		stc->map->map[stc->enemy->i][stc->enemy->j] = '0';
		map_refresh(stc, 0);
	}
	return (31);
}