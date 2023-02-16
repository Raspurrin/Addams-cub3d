/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:14 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:14:15 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img->data + (y * data->img->size_l + x * (data->img->bpp / 8));
	*(uint32_t *)dst = color;
}

uint32_t	my_mlx_pixel_get(t_texture *texture, int x, int y)
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
	return (*(uint32_t *)dst);
}
