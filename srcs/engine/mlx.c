#include "../../includes/cub3d.h"

int	get_colour(t_colour colour)
{
	int	trgb;

	trgb = colour.t << 24 | colour.r << 16 | colour.g << 8 | colour.b;
	return (trgb);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
