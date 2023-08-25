/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:47:31 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/25 20:15:23 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_struct_control *stc)
{
	int	coordinate[2];
	int	coin;
	int	i;
	int	j;

	i = -1;
	coin = 0;
	coordinate[1] = 0;
	while (++i < stc->map->mapsize_x)
	{
		j = -1;
		coordinate[0] = 0;
		while (stc->map->map[i][++j] != '\0')
		{
			put_image2(stc, stc->map->map[i][j], coordinate, &coin);
			put_image3(stc, i, j, coordinate);
			coordinate[0] += 50;
		}
		coordinate[1] += 50;
	}
	stc->ch->is_finish = 0;
	if (coin == 0)
		stc->ch->is_finish = 1;
}

void	put_image2(t_struct_control *stc, char map_c, 
	int *coordinate, int *coin)
{
	if (map_c == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->wall, 
			coordinate[0], coordinate[1]);
	else if (map_c == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->empty, 
			coordinate[0], coordinate[1]);
	else if (map_c == 'C')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->coin, 
			coordinate[0], coordinate[1]);
		*coin += 1;
	}
	else if (map_c == 'E')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->map_img->portal, 
			coordinate[0], coordinate[1]);
}

int	portal_and_check_img(t_struct_control *stc, int i, int j)
{
	if (stc->map->map[stc->ch->i][stc->ch->j] == 'X' 
		&& stc->map->map[stc->ch->i + i][stc->ch->j + j] != '1')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = 'E';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'P';
		enemy_control(stc);
		map_refresh(stc, 1);
		return (2);
	}
	if (stc->map->map[stc->ch->i + i][stc->ch->j + j] == 'E')
	{
		stc->map->map[stc->ch->i][stc->ch->j] = '0';
		stc->map->map[stc->ch->i + i][stc->ch->j + j] = 'X';
		map_refresh(stc, 1);
		enemy_control(stc);
		if (stc->ch->is_finish == 1)
		{
			ft_printf("Game Over!");
			exit(0);
		}
		return (2);
	}
	return (0);
}

void	map_refresh(t_struct_control *stc, int i)
{
	mlx_do_sync(stc->mlx);
	mlx_clear_window(stc->mlx, stc->win);
	put_image(stc);
	if (i == 1)
		step_refresh(stc, 1);
	else
		step_refresh(stc, 0);
}
