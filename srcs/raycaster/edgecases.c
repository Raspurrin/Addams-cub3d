#include "../../includes/cub3d.h"

t_vector	cond_horiz_zero(t_data *data, t_vecstack vec,
			t_vector dir, double ratio)
{
	int			cond;
	double		next_x_strich;
	t_vector	next_inter;

	cond = 0;
	ratio = vec.yup.y / TILE;
	next_x_strich = vec.yup.x / ratio;
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
	ratio = vec.yup.x / TILE;
	next_y_strich = vec.yup.y / ratio;
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
	return (!true);
}

double	ratio_is_actually_distance(t_data *data, double dist,
		t_vector first, int cond)
{
	if (cond == 2)
		dist = A_VERY_VERY_BIG_NUMMER;
	else
	{
		first = vector_substr(data->player.pos, first);
		dist = sqrt(first.x * first.x + first.y * first.y);;
	}
	return (dist);
}
