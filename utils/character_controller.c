#include "../pacman.h"

int all(struct_control *stc, int i, int j)
{
	static int step_count = 0;

	if (portal_and_check_img(stc, i, j, &step_count) == 31)
		return (0);
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' || stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		ft_printf("Step: %d\n", ++step_count);
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		map_refresh(stc);
	}
	return (0);
}

void key_left(struct_control *stc)
{
	all(stc, 0, -1);
}

void key_right(struct_control *stc)
{
	all(stc, 0, 1);
}

void key_up(struct_control *stc)
{
	all(stc, -1, 0);
}
void key_down(struct_control *stc)
{
	all(stc, 1, 0);
}

