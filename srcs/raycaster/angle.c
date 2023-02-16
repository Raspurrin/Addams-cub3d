/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:12 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:20:01 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_angle(t_vector one, t_vector two)
{
	double	dotproduct;

	dotproduct = vec_dot(normalize_vec(one), normalize_vec(two));
	if (dotproduct > 1)
		dotproduct = 1;
	return (acos(dotproduct) * (180 / M_PI));
}

double	get_next_angle(t_vector ini, t_player playa, int ray)
{
	t_vector	dir;
	t_vector	first;
	t_vector	curr;

	first = vector_substr(ini, playa.pos);
	dir = normalize_vec(rotatevectorlol(normalize_vec(playa.dir), 90));
	curr.x = ini.x + dir.x * (ray);
	curr.y = ini.y + dir.y * (ray);
	curr = vector_substr(curr, playa.pos);
	return (get_angle(first, curr));
}

t_vector	get_init_pos(t_player playa)
{
	t_vector	tamp;
	t_vector	dir;
	double		dtamp;

	tamp = normalize_vec(playa.dir);
	dir = rotatevectorlol(tamp, -90);
	dtamp = (SCREEN_WIDTH / 2) / tan((FOV / 2) * (M_PI / 180));
	tamp.x *= dtamp;
	tamp.y *= dtamp;
	tamp = vector_add(playa.pos, tamp);
	dir.x *= SCREEN_WIDTH / 2;
	dir.y *= SCREEN_WIDTH / 2;
	return (vector_add(tamp, dir));
}
