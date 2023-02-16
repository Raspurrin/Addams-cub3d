/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edgecases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:16 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 13:15:51 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	cond_horiz_zero(t_data *data, t_vecstack vec,
			t_vector dir, double ratio)
{
	int			cond;
	double		next_x_strich;
	t_vector	next_inter;

	cond = 0;
	ratio = vec.tmp.y / TILE;
	next_x_strich = vec.tmp.x / ratio;
	if (dir.y < 0)
		next_inter.y = -TILE - 0.01;
	else
		next_inter.y = TILE;
	next_inter.x = next_x_strich;
	while (cond == 0)
	{
		vec.first_inter = vector_add(vec.first_inter, next_inter);
		cond = end_condition(data, vec.first_inter);
	}
	return (vec.first_inter);
}

t_vector	cond_vert_zero(t_data *data, t_vecstack vec,
			t_vector dir, double ratio)
{
	int			cond;
	double		next_y_strich;
	t_vector	next_inter;

	cond = 0;
	ratio = vec.tmp.x / TILE;
	next_y_strich = vec.tmp.y / ratio;
	if (dir.x < 0)
		next_inter.x = -TILE - 0.01;
	else
		next_inter.x = TILE;
	next_inter.y = next_y_strich;
	while (cond == 0)
	{
		vec.first_inter = vector_add(vec.first_inter, next_inter);
		cond = end_condition(data, vec.first_inter);
	}
	return (vec.first_inter);
}

double	direction_check(t_data	*data, t_vector direction, double y, bool horiz)
{
	if (horiz)
	{
		if (direction.y > 0)
			y = TILE - fmod(data->player.pos.y, TILE);
		else
			y = fmod(data->player.pos.y, TILE);
		return (y);
	}
	else
	{
		if (direction.x > 0)
			y = TILE - fmod(data->player.pos.x, TILE);
		else
			y = fmod(data->player.pos.x, TILE);
		return (y);
	}
}

t_vector	dir_smoler_zero(t_vector direction, t_vector strich, bool horiz)
{
	if (horiz)
	{
		if (direction.y < 0)
		{
			strich.y *= (-1);
			strich.y -= 0.001;
		}
		return (strich);
	}
	else
	{
		if (direction.x < 0)
		{
			strich.x *= (-1);
			strich.x -= 0.001;
		}
		return (strich);
	}
}
