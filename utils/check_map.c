#include "../pacman.h"

map_info	*rectangle_control(map_info *map, char *map_name)
{
	int i;
	int j;
	int fd;
	char *line;

	i = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
		error_message("Dosya açılamadı!");
	line = get_next_line(fd);
	map->map = malloc(sizeof(char *)* (ft_strlen(line) + 1));
	if (!map->map)
		error_message("Bellek Hatası!");
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
			error_message("Harita dikdörtgen değil!");
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
		error_message("Haritada hata var!");
}

void	check_value(map_info *map, int i, int j)
{
	if ((map->map[0][j] != '1' || map->map[i][0] != '1' || map->map[i][map->mapsize_y - 1] != '1' 
			|| map->map[map->mapsize_x - 1][j] != '1') || (map->map[i][j] != '0' && map->map[i][j] != '1' 
			&& map->map[i][j] != 'C' && map->map[i][j] != 'P' && map->map[i][j] != 'E'))
			error_message("Haritada tanımlanamayan veriler var!");
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
void map_name_control(char *map_name)
{
	int i;
	int j;
	char *s;
	int count;

	count = 0;
	i = 0;
	j = 0;
	s = ".ber";
	while (map_name[i])
	{
		if (s[j] == map_name[i])
		{
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
		error_message(".ber dosya değil");
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

	map_name_control(map_name);
	rectangle_control(map, map_name);
	if (map->mapsize_x > 26 || map->mapsize_y > 50)
		error_message("harita boyutu fazla!");
	wall_control(map);

	return (map);
}
