/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:48:46 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/21 19:07:52 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image3(t_struct_control *stc, int i, int j, int *coordinate)
{
	if (stc->map->map[i][j] == 'P' || stc->map->map[i][j] == 'X')
	{
		if (stc->map->map[i][j] == 'X')
			mlx_put_image_to_window(stc->mlx, stc->win, 
				stc->map_img->portal_ch, coordinate[0], coordinate[1]);
		else
			mlx_put_image_to_window(stc->mlx, stc->win, 
				stc->map_img->ch, coordinate[0], coordinate[1]);
		stc->ch->i = i;
		stc->ch->j = j;
		stc->ch->x = coordinate[0];
		stc->ch->y = coordinate[1];
	}
	if (stc->map->map[i][j] == 'M')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, 
			stc->map_img->enemy, coordinate[0], coordinate[1]);
		stc->enemy->i = i;
		stc->enemy->j = j;
	}
}

int	enemy_move(t_struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != '1' 
		&& stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != 'P' 
		&& stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != 'E'
		&& stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != 'C'
		&& stc->map->map[stc->enemy->i + i][stc->enemy->j + j] != 'X')
	{
		stc->map->map[stc->enemy->i + i][stc->enemy->j + j] = 'M';
		stc->map->map[stc->enemy->i][stc->enemy->j] = '0';
		map_refresh(stc, 0);
	}
	return (31);
}
