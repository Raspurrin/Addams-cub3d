#include "../includes/cub3d.h"

int32_t	main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;
	void	*mlx;

	mlx = mlx_init();
	mlx_new_window(mlx, 1920, 1080, "yo");
	mlx_loop(mlx);
	return (0);
}
