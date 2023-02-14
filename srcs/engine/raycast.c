#include "../../includes/cub3d.h"

int		end_condition(t_data *data, t_vector vector)
{
	if (vector.x < 0 || vector.y < 0 || vector.x > (data->map_width * TILE)
		|| vector.y > (data->map_height * TILE))
		return (2);
	return(is_wall(data, vector));
}

double	horizontal_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vector	yup;
	t_vector	strich;
	t_vector	first_inter;

	if (direction.y == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	strich.y = direction_check(data, direction, strich.y);
	yup.y = just_abs(direction.y);
	yup.x = direction.x;
	ratio = yup.y / strich.y;
	strich.x = yup.x / ratio;
	strich = dir_smoler_zero(direction, strich);
	first_inter.x = data->player.pos.x + strich.x;
	first_inter.y = data->player.pos.y + strich.y;
	cond = end_condition(data, first_inter);
	if(direction.y < 0)
		strich.y += 0.001;
	if (cond == 0)
		first_inter = cond_zero(data, yup, direction, first_inter, cond, ratio);
	data->wall.pos.x = fabs(first_inter.x);
	ratio = ratio_is_actually_distance(data, ratio, first_inter, cond);
	return (ratio);
}

double	vertikal_raycast(t_data *data, t_vector direction)
{
	double		a_strich;
	double		b_strich;
	double		a;
	double		b;
	double		ratio;
	t_vector	first_inter;
	int			cond;

	if (direction.x == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	if (direction.x > 0)
		a_strich = TILE - fmod(data->player.pos.x, TILE);
	else
		a_strich = fmod(data->player.pos.x, TILE);
	a = just_abs(direction.x);
	b = direction.y;
	ratio = a / a_strich;
	b_strich = b / ratio;
	if(direction.x < 0)
	{
		a_strich *= (-1);
		a_strich -= 0.001;
	}
	// printf("next a strich %f a %f b %f\n", a_strich, a,b );
	first_inter.x = data->player.pos.x + a_strich;
	first_inter.y = data->player.pos.y + b_strich;
	cond = end_condition(data, first_inter);
	if(direction.x < 0)
		a_strich += 0.001;
	if (cond == 0)
	{
		// printf("hello\n");
		double		next_b_strich;
		t_vector	next_inter;

		ratio = a / TILE;
		next_b_strich = b /ratio;

		if(direction.x < 0)
			next_inter.x = - TILE - 0.01;
		else
			next_inter.x = TILE;
		next_inter.y = next_b_strich ;
		while (cond == 0)
		{
			first_inter = vector_add(first_inter, next_inter);
			cond = end_condition(data, first_inter);
		}
	}
	data->wall.pos.y = first_inter.y;
	double	dist;
	if (cond == 2)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		// draw_line_img(&data->canvas, data->player.pos, first_inter, 0xFFE036);
		first_inter = vector_substr(data->player.pos, first_inter); //the abs of those
		dist = calc_the_theorem(first_inter);
	}
	return (dist);
}

double	calc_the_theorem(t_vector vect)
{
	return(sqrt((vect.x * vect.x) + (vect.y * vect.y)));
}
