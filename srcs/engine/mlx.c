#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img->data + (y * data->img->size_l + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_img(t_texture *img, t_vector eins, t_vector zwei, int color)
{
	double	delta_x;
	double	delta_y;
	int		pixels;
	double	pixel_x;
	double	pixel_y;

	delta_x = zwei.x - eins.x;
	delta_y = zwei.y - eins.y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	pixel_x = eins.x;
	pixel_y = eins.y;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(img, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
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
	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return (0);
	dst = texture->img->data
		+ (y * texture->img->size_l + x * (texture->img->bpp / 8));
	return (*(unsigned int *)dst);
}

bool	is_equal(double check_input, double value, double range)
{
	if (check_input > (value - range) && check_input < (value + range))
		return (true);
	return (false);
}
