#include "../includes/cub3d.h"

// lol

// void	init(t_data *data)
// {
// 	ft_bzero(data, sizeof(data));
// 	ft_bzero(data->texture, sizeof(t_texture));
// }

int32_t	main(int argc, char const *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	// init(&data);
	data.mlx = mlx_init();
	// printf("HalpPPPPPPPPPP\n");

	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "ADDAMS?");
	// printf("Halp 1\n");
	data.img.img_ptr = mlx_new_image(data.mlx,  SCREEN_WIDTH, SCREEN_HEIGHT);
	// printf("Halp 2\n");
	// data.img.data = mlx_get_data_addr(data.img.img_ptr,
	// 		&data.img.bpp, &data.img.size_l, &data.img.endian);
	// printf("Halp 3\n");
	draw_addams_cube(&data);
	// printf("Halp 4\n");
	mlx_hook(data.win, KEY_PRESS, 0, key_handler, &data);
	// printf("Halp 5\n");
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
	// printf("Halp 6\n");
	mlx_loop(data.mlx);
	// printf("Halp 7\n");
	return (0);
}
