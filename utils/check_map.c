/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mucakmak <mucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:18:01 by mucakmak          #+#    #+#             */
/*   Updated: 2023/08/25 19:35:11 by mucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_info	*rectangle_control(t_map_info *map, char *map_name)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_message("The file could not be opened!");
	line = get_next_line(fd);
	if (!line)
		error_message("Empty Map!");
	map->map = malloc(sizeof(char *) * (ft_strlen(line) + 1));
	if (!map->map)
		error_message("Memory error!");
	while (line)
	{
		map->map[i++] = line;
		line = get_next_line(fd);
	}
	map->mapsize_x = i;
	map->mapsize_y = ft_strlen(map->map[0]);
	return (map);
}

void	wall_control(t_map_info *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->mapsize_x)
	{
		j = -1;
		while (map->map[i][++j])
		{
			check_value(map, i, j);
		}
	}
	if (map->p != 1 || map->e != 1 || map->c < 1 || map->m != 1)
		error_message("There is an error on the map!");
}

void	check_value(t_map_info *map, int i, int j)
{
	if ((map->map[0][j] != '1' || map->map[i][0] != '1' 
		|| map->map[i][map->mapsize_y - 1] != '1' 
		|| map->map[map->mapsize_x - 1][j] != '1') 
		|| (map->map[i][j] != '0' && map->map[i][j] != '1'
		&& map->map[i][j] != 'C' && map->map[i][j] != 'P' 
		&& map->map[i][j] != 'E' && map->map[i][j] != 'M'))
		error_message("There is unidentified data on the map!");
	if (map->map[i][j] == 'E')
		map->e += 1;
	else if (map->map[i][j] == 'C')
		map->c += 1;
	else if (map->map[i][j] == 'M')
		map->m += 1;
	else if (map->map[i][j] == 'P')
	{
		map->p += 1;
		map->ch_i = i;
		map->ch_j = j;
	}
}

void	map_name_control(char *map_name)
{
	int		i;
	int		j;
	char	*s;
	int		count;

	count = 0;
	i = 0;
	j = 0;
	s = ".ber";
	while (map_name[i])
	{
		if (s[j] == map_name[i])
		{
			j = 0;
			while (s[j] == map_name[i] && s[j] && map_name[i])
			{
				count++;
				j++;
				i++;
			}
		}
		i++;
	}
	if (count != 4)
		error_message("Filename extension must be .ber!");
}

t_map_info	*check_map(char *map_name)
{
	int			j;
	t_map_info	*map;

	map = malloc(sizeof(t_map_info));
	if (!map)
		exit(1);
	map->e = 0;
	map->p = 0;
	map->c = 0;
	map->m = 0;
	map_name_control(map_name);
	map_name2_control(map_name);
	rectangle_control(map, map_name);
	j = 0;
	while (j < map->mapsize_x)
		if (map->mapsize_y != ft_strlen(map->map[j++]))
			error_message("The map is not rectangular!");
	if (map->mapsize_x > 26 || map->mapsize_y > 50)
		error_message("The map is too large!");
	wall_control(map);
	return (map);
}
