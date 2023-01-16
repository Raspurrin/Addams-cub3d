#include "../includes/cub3d.h"

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(&data->legenda, sizeof(t_legenda));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_HEIGHT, SCREEN_WIDTH, "yo");
	data->legenda.north = ft_calloc(1, sizeof(t_texture));
	data->legenda.south = ft_calloc(1, sizeof(t_texture));
	data->legenda.west = ft_calloc(1, sizeof(t_texture));
	data->legenda.east = ft_calloc(1, sizeof(t_texture));
}
