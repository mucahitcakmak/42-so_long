/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:55:19 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/21 18:04:44 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/pacman.h"

t_struct_control	*images(t_struct_control *stc)
{
	int	px;
	int	py;

	stc->map_img = malloc(sizeof(t_map_images));
	stc->map_img->empty = mlx_xpm_file_to_image(stc->mlx, 
			"textures/empty.xpm", &px, &py);
	stc->map_img->wall = mlx_xpm_file_to_image(stc->mlx, 
			"textures/wall.xpm", &px, &py);
	stc->map_img->coin = mlx_xpm_file_to_image(stc->mlx, 
			"textures/coin.xpm", &px, &py);
	stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, 
			"textures/tombL.xpm", &px, &py);
	stc->map_img->ch = mlx_xpm_file_to_image(stc->mlx, 
			"textures/tombR.xpm", &px, &py);
	stc->map_img->ball = mlx_xpm_file_to_image(stc->mlx, 
			"textures/ball.xpm", &px, &py);
	stc->map_img->portal = mlx_xpm_file_to_image(stc->mlx, 
			"textures/portal.xpm", &px, &py);
	stc->map_img->portal_ch = mlx_xpm_file_to_image(stc->mlx, 
			"textures/portalCh.xpm", &px, &py);
	stc->map_img->enemy = mlx_xpm_file_to_image(stc->mlx, 
			"textures/enemy.xpm", &px, &py);
	return (stc);
}

void	error_message(char *str)
{
	ft_printf("Error:\n%s\n", str);
	exit(1);
}

int	key_code(int keycode, t_struct_control *stc)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 0)
		key_left(stc);
	else if (keycode == 1)
		key_down(stc);
	else if (keycode == 2)
		key_right(stc);
	else if (keycode == 13)
		key_up(stc);
	return (0);
}

int	close_game(char *str)
{
	if (str)
		ft_printf("%s\n", str);
	exit(0);
}

int	main(int argc, char *argv[])
{
	t_struct_control	*stc;

	if (argc != 2)
		error_message("Eksik argüman!");
	stc = malloc(sizeof(t_struct_control));
	stc->ch = malloc(sizeof(t_pacman));
	stc->enemy = malloc(sizeof(t_enemy));
	stc->mlx = mlx_init();
	stc->map = check_map(argv[1]);
	map_validation(stc->map);
	stc->win = mlx_new_window(stc->mlx, stc->map->mapsize_y * 50, 
			stc->map->mapsize_x * 50, "So_long");
	stc = images(stc);
	put_image(stc);
	mlx_hook(stc->win, 2, 1L << 0, key_code, stc);
	mlx_hook(stc->win, 17, 0L, close_game, NULL);
	mlx_loop(stc->mlx);
	return (0);
}
