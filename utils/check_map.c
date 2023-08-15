#include "../pacman.h"

static void	ft_message_error(map_info *map)
{
	if (map->map)
		free(map->map);
	free(map);
	ft_printf("Error!\nHatalı map.\n");
	exit(1);
}

map_info	*rectangle_control(map_info *map, char *map_name)
{
	int i;
	int j;
	int fd;
	char *line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		ft_message_error(map);
	line = get_next_line(fd);
	map->map = malloc(sizeof(char *)* ft_strlen(line));
	if (!map->map)
		ft_message_error(map);
	while (line)
	{
		map->map[i++] = line;
		line = get_next_line(fd);
	}
	map->mapsize_x = i;
	map->mapsize_y = ft_strlen(map->map[0]);
	j = 0;
	while (j < i)
		if (map->mapsize_y != ft_strlen(map->map[j++]))
			ft_message_error(map);
	return (map);
}


void	wall_control(map_info *map)
{
	int i;
	int j;

	i = -1;
	while (++i < map->mapsize_x)
	{
		j = -1;
		while(map->map[i][++j])
		{
			check_value(map, i, j);
		}
	}
	if (map->p != 1 || map->e != 1 || map->c < 1)
		ft_message_error(map);
}

void	check_value(map_info *map, int i, int j)
{
	if ((map->map[0][j] != '1' || map->map[i][0] != '1' || map->map[i][map->mapsize_y -1] != '1' 
			|| map->map[map->mapsize_x - 1][j] != '1') || (map->map[i][j] != '0' && map->map[i][j] != '1' 
			&& map->map[i][j] != 'C' && map->map[i][j] != 'P' && map->map[i][j] != 'E'))
			ft_message_error(map);
	if (map->map[i][j] == 'E')
		map->e +=  1;
	else if (map->map[i][j] == 'C')
		map->c += 1;
	else if (map->map[i][j] == 'P')
	{
		map->p += 1;
		map->ch_i = i;
		map->ch_j = j;
	}
}

map_info *check_map(char *map_name)
{
	map_info *map;
	map = malloc(sizeof(map_info));
	if (!map)
		exit(1);
	map->e = 0;
	map->p = 0;
	map->c = 0;

	rectangle_control(map, map_name);
	wall_control(map);

	return (map);
}

