#include "../includes/cub3d.h"

<<<<<<< HEAD
// lol

// void	init(t_data *data)
// {
// 	ft_bzero(data, sizeof(data));
// 	ft_bzero(data->texture, sizeof(t_texture));
// }

void	innit(t_data *data)
{

	char map[10][20] =	{"11111111111111111111",
						"1000P001100000001001",
						"10000001100000001001",
						"10011111100000111111",
						"10000000001110001101",
						"10000000011100001101",
						"10000000000000000001",
						"10001111000001000001",
						"10000000000011100001",
						"11111111111111111111"
					};

		int	x;
	int	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 20)
		{
			if (map[x][y] == 'P')
			{
				data->player.x = y * 100;
				// printf("player x %d\n",data->player.x);
				data->player.y = x * 100;
				// printf("player y %d\n",data->player.y);
			}
			y++;
		}
		x++;
	}
	data->player.direction.x = 0;
	data->player.direction.y = 10;
}

int32_t	main(int argc, char const *argv[])
=======
int32_t	main(int argc, char *argv[])
>>>>>>> main
{
	t_data	data;

	(void)argc;
	(void)argv;
<<<<<<< HEAD
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "ADDAMS_CUBE");
	data.img.img_ptr = mlx_new_image(data.mlx,  SCREEN_WIDTH, SCREEN_HEIGHT);
	data.img.data = mlx_get_data_addr(data.img.img_ptr,
			&data.img.bpp, &data.img.size_l, &data.img.endian);
	innit(&data);
	draw_addams_cube(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_handler, &data);
	mlx_hook(data.win, RED_CROSS, 0, x_close, &data);
=======
	init(&data);
	error_check(&data, argc, argv);
	mlx_hook(data.win, 2, 0, key_handler, &data);
	mlx_hook(data.win, 17, 0, x_close, &data);
>>>>>>> main
	mlx_loop(data.mlx);
	return (0);
}
