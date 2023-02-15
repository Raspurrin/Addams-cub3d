#include "../../includes/cub3d.h"

int	end_condition(t_data *data, t_vector vector)
{
	if (vector.x < 0 || vector.y < 0 || vector.x > (data->map_width * TILE)
		|| vector.y > (data->map_height * TILE))
		return (2);
	return (is_wall(data, vector));
}

double	horizontal_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vecstack	vec;

	if (direction.y == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	vec.strich.y = direction_check(data, direction, vec.strich.y, 1);
	vec.yup.y = just_abs(direction.y);
	vec.yup.x = direction.x;
	ratio = vec.yup.y / vec.strich.y;
	vec.strich.x = vec.yup.x / ratio;
	vec.strich = dir_smoler_zero(direction, vec.strich, 1);
	vec.first_inter.x = data->player.pos.x + vec.strich.x;
	vec.first_inter.y = data->player.pos.y + vec.strich.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.y < 0)
		vec.strich.y += 0.001;
	if (cond == 0)
		vec.first_inter = cond_horiz_zero(data, vec, direction, ratio);
	data->wall.pos.x = fabs(vec.first_inter.x);
	ratio = ratio_is_actually_distance(data, ratio, vec.first_inter, cond);
	return (ratio);
}

double	vertikal_raycast(t_data *data, t_vector direction)
{
	int			cond;
	double		ratio;
	t_vecstack	vec;

	if (direction.x == 0)
		return (A_VERY_VERY_BIG_NUMMER);
	vec.strich.x = direction_check(data, direction, vec.strich.x, 0);
	vec.yup.x = just_abs(direction.x);
	vec.yup.y = direction.y;
	ratio = vec.yup.x / vec.strich.x;
	vec.strich.y = vec.yup.y / ratio;
	vec.strich = dir_smoler_zero(direction, vec.strich, 0);
	vec.first_inter.x = data->player.pos.x + vec.strich.x;
	vec.first_inter.y = data->player.pos.y + vec.strich.y;
	cond = end_condition(data, vec.first_inter);
	if (direction.x < 0)
		vec.strich.x += 0.001;
	if (cond == 0)
		vec.first_inter = cond_vert_zero(data, vec, direction, ratio);
	data->wall.pos.y = vec.first_inter.y;
	ratio = ratio_is_actually_distance(data, ratio, vec.first_inter, cond);
	return (ratio);
}

double	calc_the_theorem(t_vector vect)
{
	return (sqrt((vect.x * vect.x) + (vect.y * vect.y)));
}
