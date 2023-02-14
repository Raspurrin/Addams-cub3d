#include "../../includes/cub3d.h"

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
			my_mlx_pixel_put(&data->canvas, data->player.pos.x + x,
				data->player.pos.y + y, 0xFFF791);
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
			my_mlx_pixel_put(&data->canvas, x, y, 0xF3C4FF);
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
			my_mlx_pixel_put(&data->canvas, x, y, 0xF3C4FF);
			y++;
		}
		x += 100;
	}
}

void	print_pos(t_data *data)
{
	printf("Player position: x = %f y = %f\n",
		data->player.pos.x, data->player.pos.y);
}
