#include "../../includes/cub3d.h"

/**
 * 150 / 100 = 1.5		| 196 / 128 = 1.5 * 100 = 150 percent		| every second pixel repeat one extra pixel
 * 250 percent - every pixel repeats and every second pixel repeats twice
 * int offset = 250 / 100 = 2.5  -  2  - repeat every line this many times
 * 250 % 100 = 50. 100 / 50 = 2. Repeat or skip with this offset (depends if previous value is 0 or not)
 */
static int32_t	calc_percentage(int32_t new_value, int32_t whole)
{
	return ((new_value / whole) * 100);
}

static int32_t	calc_interval(t_wall *wall, t_texture *texture, t_ratio *ratio)
{
	int32_t	percentage;
	int32_t	remainder;

	percentage = calc_percentage(wall->height, texture->height);
	remainder = percentage % 100; 
	if (remainder == 0)
		ratio->interval = 0;
	else
		ratio->interval = 100 / remainder;
	if (percentage == 0)
		ratio->repeat = 0;
	else
		ratio->repeat = percentage / 100;
	return ((((remainder / 100)) * texture->height) % texture->height);
}

int32_t	get_column(t_wall *wall, t_texture *texture)
{
	if (wall->direction == EAST || wall->direction == WEST)
		return (wall->pos.y % texture->width);
	else if (wall->direction == NORTH || wall->direction == SOUTH)
		return (wall->pos.x % texture->width);
	return (0);
}

// which distance do you want to make the texture at 100 % its image height? 
// Or rather which distance determines how many pixels you want to draw? 
// As texture heights can be different, that should be the deciding factor
// I need to define a certain distance as starting point, where I basically draw the entire
// texture over the screen. That 
void	draw_vertical_line(t_data *data, t_texture *texture, \
											t_wall *wall, int32_t w_x)
{
	t_ratio ratio;
	int32_t	t_x;
	int32_t	y;
	int32_t	i;

	i = 0;
	(void)texture;

	// t_x = get_column(wall, texture);
	t_x = w_x % texture->width;
	wall->height = SCREEN_HEIGHT * TILE / wall->distance;
	wall->offset = (SCREEN_HEIGHT - wall->height) / 2;
	y = calc_interval(wall, texture, &ratio);
	while (i < SCREEN_HEIGHT)
	{
		if (y < wall->offset)
			my_mlx_pixel_put(&data->img, w_x, y, data->ceiling->bgra_i);
		else if (y > wall->height + wall->offset)
			my_mlx_pixel_put(&data->img, w_x, y, data->floor->bgra_i);
		else
			my_mlx_pixel_put(&data->img, w_x, y, \
			my_mlx_pixel_get(texture->img, t_x, y % texture->height));
		if (i % ratio.repeat == 0 && i % ratio.interval != 0)
			y++;
		i++;
	}
	// calculate which percentage of texture height the distance is
	// calculate how many pixels that is to draw xd
	// calculate interval to skip or duplicate pixels
	// move pointer of texture image array
}

// void	draw_textures(t_data *data)
// {
// 	int32_t	w_x;
// 	t_wall	wall;

// 	while (w_x < SCREEN_WIDTH)
// 	{
// 		// raycaster(data, &wall);
// 		// calculate distance and get direction wall put direction in struct and return texture
// 		draw_vertical_line(data, &data->texture[wall.direction], &wall, w_x);
// 		w_x++;
// 	}
// }
