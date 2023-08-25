/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:48:46 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/25 16:23:55 by mucakmak         ###   ########.fr       */
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
	return (0);
}

void	map_name2_control(char *map_name)
{
	if (map_name[0] == '.' || map_name[5] == '.')
		error_message("Hidden file cannot be opened!");
}

int	portal_animation(t_struct_control *stc)
{
	int			x;
	static int	i = 0;

	i += 4;
	if (i < 25)
		stc->map_img->portal = mlx_xpm_file_to_image(stc->mlx, \
				"textures/portal3.xpm", &x, &x);
	else if (i < 50)
		stc->map_img->portal = mlx_xpm_file_to_image(stc->mlx, \
				"textures/portal.xpm", &x, &x);
	else if (i < 75)
		stc->map_img->portal = mlx_xpm_file_to_image(stc->mlx, \
				"textures/portal2.xpm", &x, &x);
	if (i >= 75)
		i = 0;
	mlx_clear_window(stc->mlx, stc->win);
	put_image(stc);
	step_refresh(stc, 0);
	return (0);
}
