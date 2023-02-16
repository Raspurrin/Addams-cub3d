/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:04 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 03:05:29 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	pause_game(t_data *data)
{
	if (data->pause == false)
			data->pause = true;
	else
		data->pause = false;
}

int	game_loop(void *data2)
{
	t_data	*data;

	data = (t_data *)data2;
	if (data->pause == false)
	{
		mlx_do_key_autorepeaton(data->mlx);
		move(data, data->player.movement);
		check_mouse_movement(data);
		ray_the_caster(data);
		mlx_put_image_to_window(data->mlx, data->win, \
							data->canvas.img->ptr, 0, 0);
		mlx_hook(data->win, KEY_PRESS, 0, move_on_press, data);
		mlx_hook(data->win, KEY_RELEASE, 0, move_on_release, data);
		mlx_hook(data->win, RED_CROSS, 0, x_close, data);
		mlx_mouse_hide();
	}
	printf("pause: %d\n", data->pause);
	return (0);
}
