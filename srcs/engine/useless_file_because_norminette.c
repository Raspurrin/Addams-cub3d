#include "../../includes/cub3d.h"

t_vector	cond_zero(t_data *data, t_vector yup, t_vector dir, t_vector first, int cond, double ratio)
{
	double		next_x_strich;
	t_vector	next_inter;

	ratio = yup.y / TILE;
	next_x_strich = yup.x / ratio;

	if(dir.y < 0)
		next_inter.y = - TILE - 0.01;
	else
		next_inter.y = TILE;
	next_inter.x = next_x_strich ;
	while (cond == 0)
	{
		first = vector_add(first, next_inter);
		cond = end_condition(data, first);
	}
	return (first);
}

double	direction_check(t_data	*data, t_vector direction, double y)
{
	if (direction.y > 0)
		y = TILE - fmod(data->player.pos.y, TILE);
	else
		y = fmod(data->player.pos.y, TILE);
	return (y);
}

t_vector	dir_smoler_zero(t_vector direction, t_vector strich)
{
	if(direction.y < 0)
	{
		strich.y *= (-1);
		strich.y -= 0.001;
	}
	return(strich);
}

double	ratio_is_actually_distance(t_data *data, double dist, t_vector first, int cond)
{
	if (cond == 2)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		first = vector_substr(data->player.pos, first);
		dist = calc_the_theorem(first);
	}
	return (dist);
}
