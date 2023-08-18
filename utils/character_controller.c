#include "pacman.h"

int all(struct_control *stc, int i, int j, char *ch_image_path)
{
	int pixel_x;
	int pixel_y;

	enemy_control(stc);
	if (portal_and_check_img(stc, i, j) == 31)
		return (0);
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'M')
		close_game("YOU DIED!");
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' || stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		if (i == 0)
			stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, ch_image_path, &pixel_x, &pixel_y);
		map_refresh(stc, 1);
	}
	return (0);
}

void key_left(struct_control *stc)
{
	all(stc, 0, -1, "textures/tombL.xpm");
}

void key_right(struct_control *stc)
{
	all(stc, 0, 1, "textures/tombR.xpm");
}

void key_up(struct_control *stc)
{
	all(stc, -1, 0, "textures/tombR.xpm");
}
void key_down(struct_control *stc)
{
	all(stc, 1, 0, "textures/tombR.xpm");
}

