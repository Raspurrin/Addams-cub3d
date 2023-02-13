#include "../includes/cub3d.h"

// lol

int	game_loop(void *data2)
{
	t_data	*data;

	data = (t_data *)data2;
	mlx_do_key_autorepeaton(data->mlx);
	move(data, data->player.movement);
	check_mouse_movement(data);
	draw_addams_cube(data);
	mlx_mouse_hide();
	return (0);
}

// void	texturetest(t_data *data)
// {
// 	int32_t	i;
// 	int32_t	x;
// 	int32_t	y;

// 	i = 0;
// 	printf("texture width: %d", data->texture[NORTH].width);
// 	while (i < data->texture[NORTH].width * data->texture[NORTH].height)
// 	{
// 		x = i % data->texture[NORTH].width;
// 		y = i / data->texture[NORTH].width;
// 		printf("x: %d, y: %d\n", x, y);
// 		my_mlx_pixel_put(&data->canvas, x, y,
// 			my_mlx_pixel_get(data->texture[NORTH].img, x, y));
// 		i++;
// 	}
// }

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	init(&data);
	init_image(&data, data.canvas.img);

	data.texture->height = 0;
	data.texture->width = 0;
	error_check(&data, argc, argv);
	data.canvas.height = data.map_height * TILE;
	data.canvas.width = data.map_width * TILE;
	data.mid_canvas.x = SCREEN_WIDTH / 2;
	data.mid_canvas.y = SCREEN_HEIGHT / 2;
	mlx_hook(data.win, KEY_PRESS, 0, move_on_press, &data);
	mlx_hook(data.win, KEY_RELEASE, 0, move_on_release, &data);
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
