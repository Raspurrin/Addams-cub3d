#include "../includes/cub3d.h"

int	key_handler(int keycode, t_data *data)
{
	if (keycode == ESC)
		x_close(data);
	else if (keycode == W_KEY)
		move_up(data); // +0x - 15y
	else if (keycode == S_KEY)
		move_down(data); // +0x + 15y
	else if (keycode == D_KEY)
		move_right(data); // +15x + 0y
	else if (keycode == A_KEY)
		move_left(data);  // -15x + 0y
	//else if(all other keys)
		//the functions return bools
	// if bool == true render else not
	// else 
	// 	printf("%i\n", keycode);
	return (0);
}

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}