#include "../../includes/cub3d.h"

int	colour_func(t_data *data, int iter)
{
	double	x;

	x = (double)iter / 50;
	data->colour.t = 0;
	data->colour.r = 9.0 * (1.0 - x) * x * x * x * 255;
	data->colour.g = 15.0 * ((1.0 - x) * (1.0 - x)) * x * x * 255;
	data->colour.b = 8.5 * ((1.0 - x) * (1.0 - x) * (1.0 - x)) * x * 255;
	return (get_colour(data->colour));
}

void	move_up(t_data *data)
{
	// data->plyr_x += 5;
	data->plyr_y -= 50;
	draw_addams_cube(data);
}

void	move_down(t_data *data)
{
	// data->plyr_x += 5;
	data->plyr_y += 50;
	draw_addams_cube(data);
}

void	move_right(t_data *data)
{
	data->plyr_x += 50;
	// data->plyr_y -= 5;
	draw_addams_cube(data);
}

void	move_left(t_data *data)
{
	data->plyr_x -= 50;
	// data->plyr_y -= 5;
	draw_addams_cube(data);
}

void	draw_addams_cube(t_data *data)
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
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->img, x, y, 0xBA7CE7 );
			y += 50;
		}
		x++;
	}
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->img, x, y, 0xBA7CE7 );
			y++;
		}
		x += 50;
	}
	x = 0;
	while (x < 50)
	{
		y = 0;
		while (y < 50)
		{
	    	my_mlx_pixel_put(&data->img, data->plyr_x + x, data->plyr_y + y, 0xFFF791);
			y++;		
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0,0);
}
