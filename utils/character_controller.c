/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character_controller.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:19:46 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/21 19:08:01 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all(t_struct_control *stc, int i, int j, char *ch_image_path)
{
	int	p_x;
	int	p_y;

	enemy_control(stc);
	if (portal_and_check_img(stc, i, j) == 31)
		return (0);
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'M')
		close_game("YOU DIED!");
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == '0' 
		|| stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'C')
	{
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		if (i == 0)
			stc->map_img->ch = 
				mlx_xpm_file_to_image(stc->mlx, ch_image_path, &p_x, &p_y);
		map_refresh(stc, 1);
	}
	return (0);
}

void	key_left(t_struct_control *stc)
{
	all(stc, 0, -1, "textures/tombL.xpm");
}

void	key_right(t_struct_control *stc)
{
	all(stc, 0, 1, "textures/tombR.xpm");
}

void	key_up(t_struct_control *stc)
{
	all(stc, -1, 0, "textures/tombR.xpm");
}

void	key_down(t_struct_control *stc)
{
	all(stc, 1, 0, "textures/tombR.xpm");
}
