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