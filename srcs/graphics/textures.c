#include "../../includes/cub3d.h"

// int32_t	calc_interval(int32_t distance)
// {
// 	int32_t	interval;
// 	int32_t	height_percentage;
// 	int32_t	height_pixels;

// 	return (height_pixels);
// }

// int32_t	get_column(t_wall *wall, t_texture *texture)
// {
// 	if (wall->direction == EAST || wall->direction == WEST)
// 		return (wall->pos.y % texture->width);
// 	else if (wall->direction == NORTH || wall->direction == SOUTH)
// 		return (wall->pos.x % texture->width);
// }

// which distance do you want to make the texture at 100 % its image height? 
// Or rather which distance determines how many pixels you want to draw? 
// As texture heights can be different, that should be the deciding factor
// I need to define a certain distance as starting point, where I basically draw the entire
// texture over the screen. That 
static void	draw_vertical_line(t_data *data, char *texture, \
											t_wall *wall, int32_t w_x)
{
	// int32_t	interval;
	// int32_t	offset;
	// int32_t	t_x;
	int32_t	y;

	y = 0;
	(void)texture;
	// t_x = get_column(wall);
	// interval = calc_interval(wall->distance);
	wall->height = TILE * SCREEN_HEIGHT / wall->distance;
	wall->offset = SCREEN_HEIGHT - wall->height / 2;
	while (y < SCREEN_HEIGHT)
	{
		if (y < wall->offset)
			my_mlx_pixel_put(data->win, w_x, y, data->legenda.ceiling->abgr_i);
		else if (y > wall->height + wall->offset)
			my_mlx_pixel_put(data->win, w_x, y, data->legenda.floor->abgr_i);
		else
			my_mlx_pixel_put(data->win, w_x, y, data->legenda.floor->abgr_i);
		y++;
	}
	// calculate which percentage of texture height the distance is
	// calculate how many pixels that is to draw xd
	// calculate interval to skip or duplicate pixels
	// move pointer of texture image array
}

void	draw_textures(t_data *data)
{
	int32_t	w_x;
	t_wall	wall;
	t_img	texture;

	w_x = 0;
	wall.direction = EAST;
	wall.distance = 50;
	wall.pos.y = 2;
	wall.pos.x = 2;
	wall.height = 0;
	wall.offset = 0;
	while (w_x < SCREEN_WIDTH)
	{
		// raycaster(data, &wall);
		init_image(data, &texture);
		// calculate distance and get direction wall put direction in struct and return texture
		draw_vertical_line(data, texture.data, &wall, w_x);
		w_x++;
	}
}
