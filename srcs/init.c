#include "../includes/cub3d.h"

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(&data->legenda, sizeof(t_legenda));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "yo");
	data->legenda.texture[NORTH] = ft_calloc(1, sizeof(t_texture));
	data->legenda.texture[SOUTH] = ft_calloc(1, sizeof(t_texture));
	data->legenda.texture[EAST] = ft_calloc(1, sizeof(t_texture));
	data->legenda.texture[WEST] = ft_calloc(1, sizeof(t_texture));
}

void	init_image(t_data *data, t_img *img)
{
	img->img_ptr = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	img->data = mlx_get_data_addr(img->img_ptr,
			&img->bpp, &img->size_l, &img->endian);
}
