#include "../../includes/cub3d.h"

void	move(t_data *data, bool up, bool dwn, bool rht, bool lft)
{
	// tem vec
	if (up &&  !is_wall(data, vector_add(data->player.pos, data->player.dir)))
		data->player.pos = vector_add(data->player.pos, data->player.dir);
	if (dwn && !is_wall(data, vector_substr(data->player.pos, data->player.dir)))
		data->player.pos = vector_substr(data->player.pos, data->player.dir);
	if (rht && !is_wall(data, vector_add(data->player.pos, rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_add(data->player.pos, rotatevectorlol(data->player.dir, 90));
	if (lft && !is_wall(data, vector_substr(data->player.pos, rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_substr(data->player.pos, rotatevectorlol(data->player.dir, 90));
	// check if tmp in wall
	// only if !wall update pos player
}

void	draw_addams_cube(t_data *data)
{
	ray_the_caster(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0,0);
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
	// printf("Ze akschuel %f\n", akschuel_dist);
	data->wall.distance = akschuel_dist;
}

void	ray_the_caster(t_data *data)
{
	int	count;
	double angle_view;
	data->wall.pos.y = 2;
	data->wall.pos.x = 2;
	data->wall.height = 0;
	data->wall.offset = 0;

	angle_view = ((double) FOV) / ((double)RAY_COUNT);
	count = 0;
	while (count < RAY_COUNT)
	{
		// printf("fov %i ray count %i angle view %f count %i\n", FOV, RAY_COUNT, angle_view, count);
		single_ray(data, rotatevectorlol(data->player.dir, (-1 * FOV/2) + (angle_view * count)));
		draw_vertical_line(data, &data->texture[data->wall.direction], &data->wall, count);
		count ++;
	}
	// draw_line_img(&data->img, data->player.pos, vector_add(data->player.dir, data->player.pos), 0x59D4F8);
}

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / 100;
	y = pos.x / 100;
	if(x < 0 || y < 0 || y > data->map_width - 1|| x > data->map_height - 1)
	{
		printf("SZTOPPPPPPPP!!!!!!!!, because x is %d,,,, and y is %i\n",y ,x);
		exit(1);
	}
	if (data->map[x][y] != '0')
		return (true);
	return (!true);
}

bool	is_equal(double check_input, double value, double range)
{
	if (check_input > (value - range) && check_input < (value + range ))
		return (true);
	return (false);
}

void	print_pos(t_data *data)
{
	printf("Player position: x = %f y = %f\n", data->player.pos.x, data->player.pos.y);
}