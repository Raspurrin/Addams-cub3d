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
	double		x_strich;
	double		y_strich;
	double		x;
	double		y;
	double		ratio;
	t_vector	first_inter;
	int			cond;

	if (direction.y == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	if (direction.y > 0)
		y_strich = TILE - fmod(data->player.pos.y, TILE);
	else
		y_strich = fmod(data->player.pos.y, TILE);
	y = just_abs(direction.y);
	x = direction.x;
	ratio = y / y_strich;
	x_strich = x / ratio;
	if(direction.y < 0)
	{
		y_strich *= (-1);
		y_strich -= 0.001;
	}
	first_inter.x = data->player.pos.x + x_strich;
	first_inter.y = data->player.pos.y + y_strich;
	// print_pos(data);
	cond = end_condition(data, first_inter);
	if(direction.y < 0)
		y_strich += 0.001;
	if (cond == 0)
	{
		// printf("hello\n");
		double		next_x_strich;
		t_vector	next_inter;

		ratio = y / TILE;
		next_x_strich = x /ratio;

		if(direction.y < 0)
			next_inter.y = - TILE - 0.01;
		else
			next_inter.y = TILE;
		next_inter.x = next_x_strich ;
		while (cond == 0)
		{
			first_inter = vector_add(first_inter, next_inter);
			cond = end_condition(data, first_inter);
		}
		
	}
	double	dist;
	if (cond == 2)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		// draw_line_img(&data->canvas, data->player.pos, first_inter, 0xFB00FF); //pink
		first_inter = vector_substr(data->player.pos, first_inter); //the abs of those
		dist = calc_the_theorem(first_inter);
	}
	return (dist);
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
	// printf("a strich %f a %f b %f\n", a_strich, a,b );
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
