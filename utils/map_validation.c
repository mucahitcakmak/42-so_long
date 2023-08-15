#include "../pacman.h"

void	fill(char **tab, fill_point size, fill_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return;

	tab[cur.y][cur.x] = '0';
	fill(tab, size, (fill_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (fill_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (fill_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (fill_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, fill_point size, fill_point begin)
{
	fill(tab, size, begin, 'C');
}

char **mapi_boya(map_info *map)
{
	char **clone_map;
	int i;
	int j;

	i = 0;
	clone_map = malloc(sizeof(char **) * map->mapsize_y);
	while (i < map->mapsize_x)
	{
		j = 0;
		clone_map[i] = malloc(sizeof(char *) * map->mapsize_x);
		while (j < map->mapsize_y)
		{
			clone_map[i][j] = map->map[i][j];
			if (map->map[i][j] == '0' || map->map[i][j] == 'P')
				clone_map[i][j] = 'C';
			j++;
		}
		i++;
	}
	return (clone_map);
}

void is_reachable(map_info *map, char **clone_map)
{
	int i;
	int j;

	i = 0;
	while (i < map->mapsize_x)
	{
		j = 0;
		while (j < map->mapsize_y)
		{
			if (clone_map[i][j] == 'C')
				exit(1);
			j++;
		}
		i++;
	}
}

void map_validation(map_info *map)
{
	char **clone_map;
	fill_point size;
	fill_point begin;


	size.x = map->mapsize_y;
	size.y = map->mapsize_x;
	begin.x = map->ch_j;
	begin.y = map->ch_i;
	clone_map = mapi_boya(map);
	flood_fill(clone_map, size, begin);
	is_reachable(map, clone_map);
	free(clone_map);
}
