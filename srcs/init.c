#include "../includes/cub3d.h"

void	init(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_bzero(&data->texture, sizeof(t_texture));
}
