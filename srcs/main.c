#include "../includes/cub3d.h"

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;

	init(&data);
	error_checking(&data, argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "yo");
	key_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
