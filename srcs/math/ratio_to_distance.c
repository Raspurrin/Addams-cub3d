/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio_to_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:44:27 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:44:29 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	ratio_is_actually_distance(t_data *data, double dist, \
		t_vector first, int cond)
{
	if (cond == OUT_BOUNDS)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		first = vector_substr(data->player.pos, first);
		dist = sqrt(first.x * first.x + first.y * first.y);
	}
	return (dist);
}
