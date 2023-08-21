/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:23:39 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/21 19:45:58 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../include/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <math.h>

typedef struct map_values{
	int		mapsize_x;
	int		mapsize_y;
	int		c;
	int		e;
	int		p;
	int		m;
	int		ch_i;
	int		ch_j;
	char	**map;
}	t_map_info;

typedef struct images
{
	void	*empty;
	void	*wall;
	void	*coin;
	void	*ch;
	void	*ball;
	void	*portal;
	void	*portal_ch;
	void	*enemy;
}	t_map_images;

typedef struct character
{
	int	i;
	int	j;
	int	x;
	int	y;
	int	is_finish;
}	t_pacman;

typedef struct s_point
{
	int			x;
	int			y;
}				t_fill_point;

typedef struct enemy_move
{
	int	i;
	int	j;
}	t_enemy;

typedef struct total_structs
{
	void			*mlx;
	void			*win;
	t_pacman		*ch;
	t_map_images	*map_img;
	t_map_info		*map;
	t_enemy			*enemy;
}	t_struct_control;

// include/ft_printf.c
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char *str);
void		arg_check(va_list lst, char c);
void		ft_printf(const char *str, ...);

// utils/bonus.c
void		step_refresh(t_struct_control *stc, int i);
int			enemy_control(t_struct_control *stc);
static int	ft_nbrlen(int n);
char		*ft_itoa(int n);

// utils/character_controller.c
int			all(t_struct_control *stc, int i, int j, char *ch_image_path);
void		key_left(t_struct_control *stc);
void		key_right(t_struct_control *stc);
void		key_up(t_struct_control *stc);
void		key_down(t_struct_control *stc);

// utils/check_map.c
t_map_info	*rectangle_control(t_map_info *map, char *map_name);
void		wall_control(t_map_info *map);
void		check_value(t_map_info *map, int i, int j);
void		map_name_control(char *map_name);
t_map_info	*check_map(char *map_name);

// utils/map_validation.c
void		fill(char **tab, t_fill_point size, t_fill_point cur, char to_fill);
void		flood_fill(char **tab, t_fill_point size, t_fill_point begin);
char		**paint_map(t_map_info *map);
void		is_reachable(t_map_info *map, char **clone_map);
void		map_validation(t_map_info *map);

// utils/put_image.c
void		put_image(t_struct_control *stc);
void		put_image2(t_struct_control *stc, char map_c, 
				int *coordinate, int *coin);
int			portal_and_check_img(t_struct_control *stc, int i, int j);
void		map_refresh(t_struct_control *stc, int i);

// utils/put_image2.c
void		put_image3(t_struct_control *stc, int i, int j, int *coordinate);
int			enemy_move(t_struct_control *stc, int i, int j);

// main.c
void		error_message(char *str);
int			key_code(int keycode, t_struct_control *stc);
int			close_game(char *str);

#endif