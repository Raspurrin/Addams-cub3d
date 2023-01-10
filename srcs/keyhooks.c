#include "../includes/cub3d.h"

static int32_t	closing_window(int32_t keycode, t_data *data)
{
	if (keycode == ESC || keycode == RED_CROSS)
		mlx_destroy_window(data->mlx, data->mlx);
	return (0);
}

void	key_hooks(t_data *data)
{
	mlx_key_hook(data->win, closing_window, NULL);
}
