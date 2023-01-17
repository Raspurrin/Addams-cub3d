#include "../../includes/cub3d.h"

void	move_up(t_data *data)
{
	// if (!(data->player.y - 15 <= SCREEN_HEIGHT && data->player.y - 15 > 0))
	// 	return ;
	data->player.pos.y -= 15;
	draw_addams_cube(data);
}

void	move_down(t_data *data)
{
	
	// if (!(data->player.y + 15 <= SCREEN_HEIGHT && data->player.y + 15 > 0))
	// 	return ;
	data->player.pos.y += 15;
	draw_addams_cube(data);
}

void	move_right(t_data *data)
{
	data->player.pos.x += 15;
	draw_addams_cube(data);
}

void	move_left(t_data *data)
{
	data->player.pos.x -= 15;
	draw_addams_cube(data);
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
			// printf("the x that is the y: %i\nthe y that is the x: %i\n",x,y);
			if (data->map[x][y] == '1')
			{
				// printf("zis is ze wall\n");
				draw_the_walls(data, y*100, x*100, 1);
			}
			else
			{
				// printf("zis is not ze wall\n");
				draw_the_walls(data, y*100, x*100, 0);
			}
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
			// printf("the i that is the x: %i\nthe j that is the y: %i\n",i,j);
			if (wall)
			{
				// printf("zis is ze wall\n");
				my_mlx_pixel_put(&data->img, i + x, j + y, 0xBA7CE7);
				// printf("zis is ze wall afta mlx_pxl_put\n");
			}
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

void draw_line_img(t_img *img, t_vector eins, t_vector zwei, int color)
{
	double	deltaX;
	double	deltaY;
	int 	pixels;
	double 	pixelX;
	double 	pixelY;

	deltaX = zwei.x - eins.x;
	deltaY = zwei.y - eins.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	pixelX = eins.x;
	pixelY = eins.y;
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	draw_the_vector(t_data *data)
{
	draw_line_img(&data->img, data->player.pos, vector_add(data->player.dir, data->player.pos), 0x59D4F8);
}
 