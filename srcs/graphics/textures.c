#include "../../includes/cub3d.h"

static int32_t	get_column(t_wall *wall, t_texture *texture)
{
	float	multiplier;

	multiplier = texture->width / (float)TILE;
	if (wall->direction == EAST)
		return (((int32_t)fmod(wall->pos.y, TILE)) * multiplier);
	else if (wall->direction == WEST)
		return (((int32_t)fmod(wall->pos.y, TILE)) * multiplier);
	else if (wall->direction == NORTH)
		return (((int32_t)fmod(wall->pos.x, TILE)) * multiplier);
	else if (wall->direction == SOUTH)
		return ((((int32_t)fmod(wall->pos.x, TILE))) * multiplier);
	return (0);
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

// static void    draw_wall_3d(t_data *data, int x, double dist)
// {
//     double    wall_height = WIN_HEIGTH * TILE / dist;
//     double    wall_offset = (WIN_HEIGTH - wall_height) / 2;
//     double    texture_x_d;
//     int        texture_x;

//     if(data->found_wall == NORTH_WALL || data->found_wall == SOUTH_WALL)
//         texture_x_d = fmod(data->intersection.x, TILE);
//     else
//         texture_x_d = fmod(data->intersection.y, TILE);
//     texture_x =  (int)texture_x_d;
//     int        texture_y;
//     double    y_perc;
//     texture_x = (int)(data->walls[data->found_wall].width * texture_x_d / 100);
//     for (int y = 0; y < WIN_HEIGTH; y++)
//     {
//         if (y < wall_offset)
//             my_mlx_pixel_put(&data->img, x, y, data->ceiling_col);
//         else if (y > wall_height + wall_offset)
//             my_mlx_pixel_put(&data->img, x, y, data->floor_col);
//         else
//         {
//             texture_y = y - wall_offset;
//             y_perc = (double)texture_y / wall_height;
//             texture_y = data->walls[data->found_wall].height * y_perc;
//             my_mlx_pixel_put(&data->img, x, y, my_mlx_pixel_get(data->walls[data->found_wall].img, texture_x, texture_y));
//         }
//     }
// }
