#include "../includes/cub3d.h"

int	game_loop(void *data)
{
	t_data *data2;

	data2 = (t_data *)data;
	mlx_do_key_autorepeaton(data2->mlx);
	data2->player.pos = data2->player.intention;
	draw_addams_cube(data);
	return (0);
}

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	(void)argv;
	(void)argc;
	init(&data);
	data.img.img_ptr = mlx_new_image(data.mlx,  SCREEN_WIDTH, SCREEN_HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bpp, &data.img.size_l, &data.img.endian);
	error_check(&data, argc, argv);
	// printf("halp\n");
	// print_2d_fd(data.map,1);
	draw_addams_cube(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_handler, &data);
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
