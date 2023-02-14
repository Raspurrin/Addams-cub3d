#include "../../includes/cub3d.h"

void	draw_addams_cube(t_data *data)
{
	ray_the_caster(data);
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img->ptr, 0, 0);
}

void	single_ray(t_data *data, t_vector direction)
{
	double	horizontal_dist;
	double	vertikal_dist;
	double	akschuel_dist;

	horizontal_dist = horizontal_raycast(data, direction);
	vertikal_dist = vertikal_raycast(data, direction);
	if (horizontal_dist > vertikal_dist)
	{
		if (direction.x < 0)
			data->wall.direction = WEST;
		else
			data->wall.direction = EAST;
		akschuel_dist = vertikal_dist;
	}
	else
	{
		if (direction.y < 0)
			data->wall.direction = NORTH;
		else
			data->wall.direction = SOUTH;
		akschuel_dist = horizontal_dist;
	}
	data->wall.distance = akschuel_dist / TILE;
}

static t_vector	normalize_vec(t_vector vec)
{
	t_vector	out;
	double		length;

	length = sqrt(vec.x * vec.x + vec.y * vec.y);
	out.x = vec.x / length;
	out.y = vec.y / length;
	return (out);
}

static double	vec_dot(t_vector one, t_vector two)
{
	t_vector	tmp1;
	t_vector	tmp2;

	tmp1 = normalize_vec(one);
	tmp2 = normalize_vec(two);
	return ((tmp1.x * tmp2.x) + (tmp1.y * tmp2.y));
}

void	ray_the_caster(t_data *data)
{
	double		angle_view;
	double		radiant_diff;
	double		i_dont_know;
	t_vector	tmp;
	t_intvector	draw;

	angle_view = ((double) FOV) / ((double)RAY_COUNT);
	draw.x = 0;
	draw.y = 0;
	while (draw.x < RAY_COUNT)
	{
		tmp = rotatevectorlol(data->player.dir,
				(-1 * FOV / 2) + (angle_view * draw.x));
		single_ray(data, tmp);
		if (draw.x != RAY_COUNT / 2)
		{
			i_dont_know = vec_dot(data->player.dir, tmp);
			radiant_diff = acos(i_dont_know);
			data->wall.distance *= cos(radiant_diff);
		}
		draw_vertical_line(data, &(data->texture)
		[data->wall.direction], &data->wall, draw);
		draw.x++;
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
