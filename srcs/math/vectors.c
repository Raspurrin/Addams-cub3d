/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:32 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 02:42:32 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/engine.h"

t_vector	vector_substr(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x - second.x;
	vector.y = first.y - second.y;
	return (vector);
}

t_vector	vector_add(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x + second.x;
	vector.y = first.y + second.y;
	return (vector);
}

t_vector	vector_multpl(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = (first.x * second.x) - (first.y * second.y);
	vector.y = 2 * (first.x * second.y);
	return (vector);
}

t_vector	rotatevectorlol(t_vector vct, double angle)
{
	t_vector	tmp;

	tmp.x = vct.x;
	tmp.y = vct.y;
	vct.x = (tmp.x * cos(angle * M_PI / 180))
		- (tmp.y * sin(angle * M_PI / 180));
	vct.y = (tmp.x * sin(angle * M_PI / 180))
		+ (tmp.y * cos(angle * M_PI / 180));
	return (vct);
}

double	vec_dot(t_vector one, t_vector two)
{
	t_vector	tmp1;
	t_vector	tmp2;

	tmp1 = normalize_vec(one);
	tmp2 = normalize_vec(two);
	return ((tmp1.x * tmp2.x) + (tmp1.y * tmp2.y));
}
