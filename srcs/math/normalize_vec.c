/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_vec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:26 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:14:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_vector	normalize_vec(t_vector vec)
{
	t_vector	out;
	double		length;

	length = sqrt(vec.x * vec.x + vec.y * vec.y);
	out.x = vec.x / length;
	out.y = vec.y / length;
	return (out);
}
