#include "../../includes/cub3d.h"

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	x = data->player.pos.x/M_TILE;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (data->map[x][y] == '1')
				draw_the_walls(data, y*M_TILE, x*M_TILE, 1);
			else
				draw_the_walls(data, y*M_TILE, x*M_TILE, 0);
			y++;
		}
		x++;
	}
	draw_the_grid(data);
	// draw_player(data); // i dont agree with this (angry exclamation mark)
}

void	draw_the_walls(t_data *data, int x, int y, bool wall)
{
	int	i;
	int	j;

	i = 0;
	while (i <20)
	{
		j = 0;
		while (j < 20)
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
	while (x < M_TILE/5)
	{
		y = 0;
		while (y < M_TILE/5)
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
	while (x < M_TILE * 10)
	{
		y = 0;
		while (y < M_TILE * 10)
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
	while (x < M_TILE * 10)
	{
		y = 0;
		while (y < M_TILE * 10)
		{
            my_mlx_pixel_put(&data->img, x, y, 0xF3C4FF );
			y += M_TILE;
		}
		x++;
	}
	x = 0;
	while (x < M_TILE * 10)
	{
		y = 0;
		while (y < M_TILE * 10)
		{
			my_mlx_pixel_put(&data->img, x, y, 0xF3C4FF );
			y++;
		}
		x += M_TILE;
	}
}
