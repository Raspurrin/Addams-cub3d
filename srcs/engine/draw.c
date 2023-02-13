#include "../../includes/cub3d.h"

void	move(t_data *data, bool up, bool dwn, bool rht, bool lft)
{
	// tem vec
	t_vector temp;
	temp.x = data->player.dir.x;
	temp.y = data->player.dir.y;
	if (up &&  !is_wall(data, vector_add(data->player.pos, temp)))
		data->player.pos = vector_add(data->player.pos, data->player.dir);
	if (dwn && !is_wall(data, vector_substr(data->player.pos, temp)))
		data->player.pos = vector_substr(data->player.pos, data->player.dir);
	if (rht && !is_wall(data, vector_add(data->player.pos, rotatevectorlol(temp, 90))))
		data->player.pos = vector_add(data->player.pos, rotatevectorlol(data->player.dir, 90));
	if (lft && !is_wall(data, vector_substr(data->player.pos, rotatevectorlol(temp, 90))))
		data->player.pos = vector_substr(data->player.pos, rotatevectorlol(data->player.dir, 90));
	// check if tmp in wall
	// only if !wall update pos player
}

void	draw_addams_cube(t_data *data)
{
	// int	x;
	// int	y;
	// x = 0;
	// while (x < 10)
	// {
	// 	y = 0;
	// 	while (y < 20)
	// 	{
	// 		if (data->map[x][y] == '1')
	// 			draw_the_walls(data, y*100, x*100, 1);
	// 		else
	// 			draw_the_walls(data, y*100, x*100, 0);
	// 		y++;
	// 	}
	// 	x++;
	// }
	// draw_the_grid(data);
	// draw_player(data); // i dont agree with this (angry exclamation mark)
	ray_the_caster(data);
	mlx_put_image_to_window(data->mlx, data->win, data->canvas.img->ptr, 0,0);
}

void	draw_the_walls(t_data *data, int x, int y, bool wall)
{
	int	i;
	int	j;

	i = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			if (wall)
				my_mlx_pixel_put(&data->canvas, i + x, j + y, 0xBA7CE7);
			else
				my_mlx_pixel_put(&data->canvas, i + x, j + y, 0x000000);
			j++;
		}
		i++;
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < 25)
	{
		y = 0;
		while (y < 25)
		{
			my_mlx_pixel_put(&data->canvas, data->player.pos.x + x, data->player.pos.y + y, 0xFFF791);
			y++;		
		}
		x++;
	}
}

void	draw_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->canvas, x, y, 0x0000000);
			y ++;
		}
		x++;
	}
}

void	draw_the_grid(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->canvas, x, y, 0xF3C4FF );
			y += 100;
		}
		x++;
	}
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->canvas, x, y, 0xF3C4FF );
			y++;
		}
		x += 100;
	}
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
	data->wall.distance = akschuel_dist / TILE;
}

void	ray_the_caster(t_data *data)
{
	t_intvector	draw;
	double		angle_view;

	angle_view = ((double) FOV) / ((double)RAY_COUNT);
	draw.x = 0;
	draw.y = 0;
	while (draw.x < RAY_COUNT)
	{
		single_ray(data, rotatevectorlol(data->player.dir, (-1 * FOV/2) + (angle_view * draw.x)));
		printf("x pos: %f y pos: %f\n", data->wall.pos.x, data->wall.pos.y);
		draw_vertical_line(data, &(data->texture)[data->wall.direction], &data->wall, draw);
		draw.x++;
	}
	printf("-------------\n");
}

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / 100; // was dis?
	y = pos.x / 100;
	if (x < 0 || y < 0 || y > data->map_width - 1|| x > data->map_height - 1)
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
