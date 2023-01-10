#include "../includes/cub3d.h"

int32_t	main(int argc, char const *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "yo");
	key_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
