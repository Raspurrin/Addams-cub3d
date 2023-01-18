#include "../../includes/cub3d.h"

void	move(t_data *data, bool up, bool dwn, bool rht, bool lft)
{

	// if (!(data->player.pos.y - 15 <= SCREEN_HEIGHT && data->player.pos.y - 15 > 0))
	// 	return ;
	// if (!(data->player.pos.y + 15 <= SCREEN_HEIGHT && data->player.pos.y + 15 > 0))
	// 	return ;
	// if (!(data->player.pos.x - 15 <= SCREEN_WIDTH && data->player.pos.x - 15 > 0))
	// 	return ;
	// if (!(data->player.pos.x + 15 <= SCREEN_WIDTH && data->player.pos.x + 15 > 0))
	// 	return ;
	if (up)
		data->player.pos = vector_add(data->player.pos,  data->player.dir);
	if (dwn)
		data->player.pos = vector_substr(data->player.pos,  data->player.dir);
	if (rht)
		data->player.pos = vector_add(data->player.pos,  rotatevectorlol(data->player.dir, 90));
	if (lft)
		data->player.pos = vector_substr(data->player.pos,  rotatevectorlol(data->player.dir, 90));
}

// void	move_down(t_data *data)
// {
	
// 	// if (!(data->player.y + 15 <= SCREEN_HEIGHT && data->player.y + 15 > 0))
// 	// 	return ;
// 	data->player.pos.y += 15;
// }

// void	move_right(t_data *data)
// {
// 	data->player.pos.x += 15;
// }

// void	move_left(t_data *data)
// {
// 	data->player.pos.x -= 15;
// }

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
	// int	x;
	// int	y;
	// t_vector map; // the /100 one 
	// t_vector temp; // the *100 one
	// temp.x = data->player.pos.y / TILE;  //3
	// temp.y = data->player.pos.x / TILE;  //6
		// printf("the x that is the y: %f\nthe y that is the x: %f\n",temp.x,temp.y);
	// x = data->player.pos.y / TILE;
	// y = data->player.pos.x / TILE;
	// while (data->map[(int)temp.x][(int)temp.y] != '0' && data->map[(int)temp.x][(int)temp.y] != 'W')
	// {
	// 	temp.x = temp.x * TILE;  //300
	// 	temp.y = temp.y * TILE;  //600
	// 	temp = vector_add(temp, data->player.dir);
	// 	temp.x = temp.x / TILE;  //3
	// 	temp.y = temp.y / TILE;  //6
	// }
	// printf("%f %f\n", temp.x, temp.y);
	// if (!(data->player.pos.y - DIR_VECTOR <= SCREEN_HEIGHT && data->player.pos.y - DIR_VECTOR > 0))
	// 	return ;
	// if (!(data->player.pos.y + DIR_VECTOR <= SCREEN_HEIGHT && data->player.pos.y + DIR_VECTOR > 0))
	// 	return ;
	// if (!(data->player.pos.x - DIR_VECTOR <= SCREEN_WIDTH && data->player.pos.x - DIR_VECTOR > 0))
	// 	return ;
	// if (!(data->player.pos.x + DIR_VECTOR <= SCREEN_WIDTH && data->player.pos.x + DIR_VECTOR > 0))
	// 	return ;
	draw_line_img(&data->img, data->player.pos, vector_add(data->player.dir, data->player.pos), 0x59D4F8);
	
}
 