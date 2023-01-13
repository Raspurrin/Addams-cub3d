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

void	draw_addams_cube(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT/2)
		{
            my_mlx_pixel_put(&data->img, x, y, 0xBA7CE7 );
			y+=10;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0,0);
	x = 0;
	while (x < SCREEN_WIDTH/2)
	{
		y = 0;
		while (y < SCREEN_HEIGHT)
		{
            my_mlx_pixel_put(&data->img, x, y, 0xBA7CE7 );
			y++;
		}
		x+=10;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0,0);
    
}
