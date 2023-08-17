#include "pacman.h"

void error_message(char *str)
{
	ft_printf("Error:\n%s\n", str);
	exit(1);
}

int key_code(int keycode, struct_control *stc)
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

int close_game(void *param)
{
    exit(0);
}

int main(int argc, char *argv[])
{
	struct_control *stc;
	
	if (argc != 2)
		error_message("Eksik argüman!");
	stc = malloc(sizeof(struct_control));
	stc->ch = malloc(sizeof(pacman));
	stc->mlx = mlx_init();
	stc->map = check_map(argv[1]);
	map_validation(stc->map);
    stc->win = mlx_new_window(stc->mlx, stc->map->mapsize_y * 50, stc->map->mapsize_x * 50, "Puzzle");
	stc = images(stc);
	put_image(stc);
	mlx_hook(stc->win, 2, 1L << 0, key_code, stc);
    mlx_hook(stc->win, 17, 0L, close_game, NULL);
	mlx_loop(stc->mlx);
    return 0;
}
