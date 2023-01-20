#include "../../includes/cub3d.h"

void	init_draw_textures(t_legenda *legenda, t_draw_textures *draw_textures)
{
	draw_textures->texture[NORTH] = legenda->north;
	draw_textures->texture[SOUTH] = legenda->south;
	draw_textures->texture[WEST] = legenda->west;
	draw_textures->texture[EAST] = legenda->east;
	draw_textures->distance = 0;
	draw_textures->direction = 0;
}

int32_t	calc_interval(int32_t distance)
{
	int32_t	interval;
	int32_t	height_percentage;
	int32_t	height_pixels;

	return (height_pixels);
}

// which distance do you want to make the texture at 100 % its image height? 
// Or rather which distance determines how many pixels you want to draw? 
// As texture heights can be different, that should be the deciding factor
// I need to define a certain distance as starting point, where I basically draw the entire
// texture over the screen. That 
void	draw_vertical_line(t_data *data, t_draw_textures *draw_textures, \
											int32_t direction, int32_t line)
{
	t_texture texture;
	int32_t
	
	calc_interval(distance);
	// calculate which percentage of texture height the distance is
	// calculate how many pixels that is to draw xd
	// calculate interval to skip or duplicate pixels
	// move pointer of texture image array
}

void	draw_textures(t_data *data)
{
	int32_t	line;
	int32_t	direction;
	t_draw_textures	draw_textures;

	line = 0;
	init_draw_textures(&data->legenda, &draw_textures);
	while (line < data->map_width)
	{
		direction = raycaster(data, &draw_textures);
		// calculate distance and get direction wall put direction in struct and return texture
		draw_vertical_line(data, &draw_textures, direction, line);
		line++;
	}
}

// t_texture *update_texture(t_draw_textures *draw_textures)
// {
// 	if (draw_textures.direction == NORTH)
// 		return (draw_textures->texture[SOUTH]);
// 	if (draw_textures.direction == SOUTH)
// 		return (draw_textures->texture[SOUTH]);
// 	if (draw_textures.direction == WEST)
// 		return (draw_textures->texture[SOUTH]);
// 	if (draw_textures.direction == EAST)
// 		return (draw_textures->texture[SOUTH]);
// }
