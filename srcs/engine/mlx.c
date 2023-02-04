#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_line_img(t_img *img, t_vector eins, t_vector zwei, int color)
{
	double	deltaX;
	double	deltaY;
	int 	pixels;
	double 	pixelX;
	double 	pixelY;

	deltaX = zwei.x - eins.x;
	deltaY = zwei.y - eins.y;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	pixelX = eins.x;
	pixelY = eins.y;
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(img, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

double	just_abs(double i)
{
	if (i >= 0)
		return (i);
	else
		return (-1 * i);
}
unsigned int	my_mlx_pixel_get(t_texture *texture, int x, int y)
{
	char	*dst;

	if (y >= texture->height)
		y = texture->height - 1;
	if (x >= texture->width)
		x = texture->width - 1;
	dst = texture->img->data + (y * texture->img->size_l + x * (texture->img->bpp / 8));
	return (*(unsigned int *)dst);
}
