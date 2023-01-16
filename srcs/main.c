#include "../includes/cub3d.h"

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	(void)argc;
	(void)argv;
	init(&data);
	
	error_check(&data, argc, argv);
	key_hooks(&data);
	mlx_loop(data.mlx);
	return (0);
}
