#include "../includes/cub3d.h"

//lol

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	init(&data);
	data.img.img_ptr = mlx_new_image(data.mlx,  SCREEN_WIDTH, SCREEN_HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bpp, &data.img.size_l, &data.img.endian);
	error_check(&data, argc, argv);
	draw_addams_cube(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_handler, &data);
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
