#include "../includes/cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		x_close(data);
	else if (keycode == W_KEY)
		move(data, 1,0,0,0);
	else if (keycode == S_KEY)
		move(data, 0,1,0,0);
	else if (keycode == D_KEY)
		move(data, 0,0,1,0);
	else if (keycode == A_KEY)
		move(data, 0,0,0,1);
	else if (keycode == ARROW_RIGHT)
		data->player.dir = rotatevectorlol(data->player.dir, 10);
	else if (keycode == ARROW_LEFT)
		data->player.dir = rotatevectorlol(data->player.dir, -10);
	draw_addams_cube(data);
	return (0);
}

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}