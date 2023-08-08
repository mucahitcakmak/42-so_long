#include "../pacman.h"

void movement(struct_control *stc, int i, int j)
{
	
	if (stc->map->map[i][j] != '1')
	{
		mlx_clear_window(stc->mlx, stc->win);
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map->map[i][j] = 'P';
		put_image(stc);
	}
}

void key_left(struct_control *stc)
{
	//while(stc->map->map[stc->ch->i][stc->ch->j - 1] != '1')
	//{
	//}
	movement(stc, stc->ch->i, stc->ch->j - 1);
}
void key_right(struct_control *stc)
{
	movement(stc, stc->ch->i, stc->ch->j +1);
}
void key_up(struct_control *stc)
{
	movement(stc, stc->ch->i - 1, stc->ch->j);
}
void key_down(struct_control *stc)
{
	movement(stc, stc->ch->i + 1, stc->ch->j);
}

