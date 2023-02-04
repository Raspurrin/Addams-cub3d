#include "../../includes/cub3d.h"

#define OUTSIDE 2

int		find_start(int var)
{
	if (var - 3 < 0)
		return (0);
	return (var - 3);
}

int		is_wall_minimap(t_data *data, int x, int y)
{
	int		y_max;
	char	**tmp;

	tmp = data->map;
	y_max = 0;
	printf("test1\n");
	while (tmp[y_max++])
		printf("test2\n");;
	printf("test\n");
	// data->map_height
	if (y >= y_max || y < 0)
		return (OUTSIDE);
	if(x >= (int)ft_strlen(tmp[y]) || x < 0)
		return (OUTSIDE);
	return (data->map[y][x]);
	

	// if(x < 0 || y < 0 || y > data->map_width - 1|| x > data->map_height - 1)
	// {
	// 	printf("SZTOPPPPPPPP!!!!!!!!, because x is %d,,,, and y is %i\n",y ,x);
	// 	exit(1);
	// }
	// if (data->map[x][y] != '0')
	// 	return (true);
	// return (!true);
}

void	draw_minimap(t_data *data)
{
	// int	s_x = find_start((int)(data->player.pos.x / TILE));
	// int	e_x = s_x + 7;

	// printf("%f %f\n", data->player.pos.x, data->player.pos.y);
	// (void)s_x;

	// printf("starts x y %i %i \n", s_x, s_y);

	// while (s_x < e_x)
	// {
	// 	int	s_y = find_start((int)(data->player.pos.y / TILE));
	// 	int	e_y = s_y + 7;
	// 	while (s_y < e_y)
	// 	{
	// 		if (data->map[y][x] == '1')
	// 			draw_the_walls(data, x*M_TILE, y*M_TILE, 1);
	// 		else
	// 			draw_the_walls(data, x*M_TILE, y*M_TILE, 0);
	// 		y++;
	// 		s_y++;
	// 	}
	// 	s_x++;
	// }

	printf("test = %i\n", is_wall_minimap(data, -1, 1));
	
}
// void	draw_minimap(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	i;
// 	x = 0;
// 	y = 0;
// 	i = 0;
// 	x = (data->player.pos.x / TILE) - 3;
// 	i =  x + 6;

// 	int	s_x = find_start((int)(data->player.pos.x / 100));
// 	int	s_y = find_start((int)(data->player.pos.y / 100));;


// 	printf("%f %f\n", data->player.pos.x, data->player.pos.y);
// 	(void)s_x;
// 	(void)s_y;

// 	printf("starts x y %i %i \n", s_x, s_y);

// 	printf("%i %i %i\n",x ,y , i);
// 	while (x < i)
// 	{
// 		y = ((data->player.pos.y) / TILE) - 3;
// 		while (y < i)
// 		{
// 			if (data->map[y][x] == '1')
// 				draw_the_walls(data, x*M_TILE, y*M_TILE, 1);
// 			else
// 				draw_the_walls(data, x*M_TILE, y*M_TILE, 0);
// 			y++;
// 		}
// 		x++;
// 	}
// 	draw_the_grid(data);
// 	// draw_player(data); // i dont agree with this (angry exclamation mark)
// }

void	draw_the_walls(t_data *data, int x, int y, bool wall)
{
	int	i;
	int	j;

	i = 0;
	while (i < M_TILE)
	{
		j = 0;
		while (j < M_TILE)
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
	while (x < M_TILE)
	{
		y = 0;
		while (y < M_TILE)
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
