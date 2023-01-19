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
	int	x;
	int	y;
	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 20)
		{
			if (data->map[x][y] == '1')
				draw_the_walls(data, y*100, x*100, 1);
			else
				draw_the_walls(data, y*100, x*100, 0);
			y++;
		}
		x++;
	}
	draw_the_grid(data);
	draw_player(data);
	draw_the_vector(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0,0);
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
				my_mlx_pixel_put(&data->img, i + x, j + y, 0xBA7CE7);
			else
				my_mlx_pixel_put(&data->img, i + x, j + y, 0x000000);
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
			my_mlx_pixel_put(&data->img, data->player.pos.x + x, data->player.pos.y + y, 0xFFF791);
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
            my_mlx_pixel_put(&data->img, x, y, 0x0000000);
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
            my_mlx_pixel_put(&data->img, x, y, 0xF3C4FF );
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
            my_mlx_pixel_put(&data->img, x, y, 0xF3C4FF );
			y++;
		}
		x += 100;
	}
}

void	draw_the_vector(t_data *data)
{
	single_raycast(data, data->player.pos, data->player.dir);
	draw_line_img(&data->img, data->player.pos, vector_add(data->player.dir, data->player.pos), 0x59D4F8);
	
}

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / 100;
	y = pos.x / 100;
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

double	single_raycast(t_data *data, t_vector pos, t_vector dir)
{
	double	og_x;
	double	og_y;
	double	ratio;
	t_vector	ray;

	if (!is_equal(dir.y, 0, 0.001))
	{
		printf("jelloooooooo\n");
		ratio = dir.x / dir.y;
	}
	else
	{
		printf("jeeeeeeello\n");
		ratio = dir.x / 0.1;
	}

	og_x = TILE - fmod(pos.x, TILE);
	og_y = ratio / og_x;

	ray.x = data->player.pos.x + og_x;
	ray.y = data->player.pos.y + og_y;
		// printf("x: %f, y: %f\n", ray.x, ray.y);
	draw_line_img(&data->img, data->player.pos, ray, 0xFFE036);
	return (og_y);
}