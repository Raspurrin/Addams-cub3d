/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:09 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 13:41:26 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / 100;
	y = pos.x / 100;
	if (x < 0 || y < 0 || y > data->map_width - 1 || x > data->map_height - 1)
	{
		printf("SZTOPPPPPPPP!!!!!!!!, because x is %d,,,, and y is %i\n", y, x);
		exit(1);
	}
	if (data->map[x][y] != '0')
		return (true);
	return (false);
}

void	move(t_data *data, int32_t movement)
{
	t_vector	temp;

	temp.x = data->player.dir.x * 0.3;
	temp.y = data->player.dir.y * 0.3;
	if (movement & UP && !is_wall(data, \
		vector_add(data->player.pos, data->player.dir)))
		data->player.pos = vector_add(data->player.pos, temp);
	if (movement & DOWN && !is_wall(data, \
		vector_substr(data->player.pos, data->player.dir)))
		data->player.pos = vector_substr(data->player.pos, temp);
	if (movement & RIGHT && !is_wall(data, \
		vector_add(data->player.pos, rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_add(data->player.pos, \
								rotatevectorlol(temp, 90));
	if (movement & LEFT && !is_wall(data, vector_substr(data->player.pos, \
									rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_substr(data->player.pos, \
									rotatevectorlol(temp, 90));
	if (movement & TURN_LEFT)
		data->player.dir = rotatevectorlol(data->player.dir, -5);
	if (movement & TURN_RIGHT)
		data->player.dir = rotatevectorlol(data->player.dir, 5);
}

void	check_mouse_movement(t_data *data)
{
	t_intvector	mouse;

	mlx_mouse_get_pos(data->win, &mouse.x, &mouse.y);
	if (mouse.x < data->mid_canvas.x)
		data->player.dir = rotatevectorlol(data->player.dir, \
							(data->mid_canvas.x - mouse.x) * -0.15);
	else if (mouse.x > data->mid_canvas.x)
		data->player.dir = rotatevectorlol(data->player.dir, \
							(mouse.x - data->mid_canvas.x) * 0.15);
	mlx_mouse_move(data->win, data->mid_canvas.x, data->mid_canvas.y);
}

int	move_on_press(int keycode, t_data *data)
{
	if (keycode == SPACE)
		pause_game(data);
	if (keycode == ESC)
		x_close(data);
	else if (keycode == W_KEY)
		data->player.movement = data->player.movement | UP;
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement | DOWN;
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement | RIGHT;
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement | LEFT;
	else if (keycode == ARROW_LEFT)
		data->player.movement = data->player.movement | TURN_LEFT;
	else if (keycode == ARROW_RIGHT)
		data->player.movement = data->player.movement | TURN_RIGHT;
	return (0);
}

int	move_on_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.movement = data->player.movement & ~UP;
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement & ~DOWN;
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement & ~RIGHT;
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement & ~LEFT;
	else if (keycode == ARROW_LEFT)
		data->player.movement = data->player.movement & ~TURN_LEFT;
	else if (keycode == ARROW_RIGHT)
		data->player.movement = data->player.movement & ~TURN_RIGHT;
	return (0);
}
