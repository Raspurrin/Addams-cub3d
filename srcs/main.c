#include "../includes/cub3d.h"

int	game_loop(void *data)
{
	t_data	*data2;

	data2 = (t_data *)data;
	mlx_do_key_autorepeaton(data2->mlx);
	 
	// draw_addams_cube(data);
	return (0);
}

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	(void)argv;
	(void)argc;
	init(&data);
	init_image(&data, &data.img);
	error_check(&data, argc, argv);
	draw_textures(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.ptr, 0,0);
	// printf("halp\n");
	// print_2d_fd(data.map,1);
	// draw_addams_cube(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_handler, &data);
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
	// mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
