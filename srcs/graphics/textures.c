#include "../../includes/cub3d.h"


static float	calc_multiplier(float whole, float new_value)
{
	return (1 * (whole / new_value));
}

static int32_t	get_column(t_wall *wall, t_texture *texture)
{
	float	multiplier;

	multiplier = calc_multiplier(texture->width, TILE);
	if (wall->direction == EAST)
		return (((int32_t)wall->pos.y % TILE) * multiplier);
	else if (wall->direction == WEST)
		return ((TILE - ((int32_t)wall->pos.y % TILE)) * multiplier);
	else if (wall->direction == NORTH)
		return (((int32_t)wall->pos.x % TILE) * multiplier);
	else if (wall->direction == SOUTH)
		return ((TILE - (int32_t)wall->pos.x % TILE) * multiplier);
	return (0);
}

static void	draw_wall(t_data *data, t_texture *texture, t_intvector *draw)
{
	uint32_t	i;
	t_intvector	img;
	float		multiplier;

	i = 0;
	multiplier = calc_multiplier(texture->height, data->wall.height);
	img.x = get_column(&data->wall, texture);
	printf("%d\n", img.x);
	while (i < data->wall.height - 1)
	{
		if (draw->y < SCREEN_HEIGHT - 1 && draw->x < SCREEN_WIDTH - 1)
			my_mlx_pixel_put(&data->canvas, draw->x, draw->y, \
			my_mlx_pixel_get(data->texture, img.x, i * multiplier));
		i++;
		draw->y++;
	}
}

void	draw_vertical_line(t_data *data, t_texture *texture, t_wall *wall, t_intvector draw)
{
	wall->height = SCREEN_HEIGHT * 20 / wall->distance;
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
