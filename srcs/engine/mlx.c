#include "../../includes/cub3d.h"

// ugly fucking protection because I am about to get blackholed idec 
// also I am beautiful and smart and I have a lot of people who really care about me
// also I'm gonna die
// how bout no
// see people no care
void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	// if (y >= data->height)
	// {
	// 	// if (data->height == 0)
	// 	// 	y = 0;
	// 	// else 
	// 		y = data->height - 1;
	// }
	// if (x >= data->width)
	// {
	// 	// if (data->width == 0)
	// 	// 	x = 0;
	// 	// else
	// 		x = data->width - 1;
	// }
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img->data + (y * data->img->size_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void draw_line_img(t_texture *img, t_vector eins, t_vector zwei, int color)
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

	if (y >= texture->height && texture->height != 0)
		y = texture->height - 1;
	if (x >= texture->width && texture->width != 0)
		x = texture->width - 1;
	dst = texture->img->data + (y * texture->img->size_l + x * (texture->img->bpp / 8));
	return (*(unsigned int *)dst);
}
