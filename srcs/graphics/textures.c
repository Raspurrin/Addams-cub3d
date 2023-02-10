#include "../../includes/cub3d.h"

static double	get_column(t_wall *wall, t_texture *texture)
{
	double	multiplier;
	double	column;

	column = 0.0;
	multiplier = texture->width / (double)TILE;
	if (wall->direction == EAST)
		column = fmod(wall->pos.y, TILE) * multiplier;
	else if (wall->direction == WEST)
		column = fmod(wall->pos.y, TILE) * multiplier;
	else if (wall->direction == NORTH)
		column = fmod(wall->pos.x, TILE) * multiplier;
	else if (wall->direction == SOUTH)
		column = fmod(wall->pos.x, TILE) * multiplier;
	return (column);
}

static int32_t	get_start_row(t_wall wall)
{
	if (wall.height > SCREEN_HEIGHT)
		return ((wall.height - SCREEN_HEIGHT) / 2);
	return (0);
}

static void	draw_wall(t_data *data, t_texture *texture, t_intvector *draw)
{
	uint32_t	i;
	t_intvector	img;
	float		multiplier;

	i = get_start_row(data->wall);
	multiplier = texture->height / (float)data->wall.height;
	img.x = get_column(&data->wall, texture);
	while (i < data->wall.height - 1)
	{
		if (draw->y < SCREEN_HEIGHT - 1 && draw->x < SCREEN_WIDTH - 1)
			my_mlx_pixel_put(&data->canvas, draw->x, draw->y, \
			my_mlx_pixel_get(texture, img.x, i * multiplier));
		i++;
		draw->y++;
	}
}

void	draw_vertical_line(t_data *data, t_texture *texture, t_wall *wall, t_intvector draw)
{
	wall->height = SCREEN_HEIGHT / wall->distance;
	if (wall->height > SCREEN_HEIGHT)
		wall->offset = 0;
	else
		wall->offset = (SCREEN_HEIGHT - wall->height) / 2;
	while ((uint32_t)draw.y < wall->offset)
		my_mlx_pixel_put(&data->canvas, draw.x, draw.y++, data->ceiling->bgra_i);
	draw_wall(data, texture, &draw);
	wall->offset = wall->height + (wall->offset * 2);
	while ((uint32_t)draw.y < wall->offset)
		my_mlx_pixel_put(&data->canvas, draw.x, draw.y++, data->floor->bgra_i);
}
