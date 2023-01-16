#include "../includes/cub3d.h"

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	error_check(&data, argc, argv);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_hook(data.win, 17, 0, x_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
