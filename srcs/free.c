/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:29 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 11:15:42 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_texture(t_texture *texture)
{
	size_t	i;

	i = 0;
	while (i < TEXTCOUNT)
	{
		if (texture[i].img->ptr)
			free(texture[i].img->ptr);
		if (texture[i].img->data)
			free(texture[i].img->data);
		if (texture[i].img)
			free(texture[i].img);
		i++;
	}
}

void	free_data(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
	if (data->map)
		free_2d_guard(&data->map);
	free_texture(data->texture);
	if (data->floor)
		free(data->floor);
	if (data->ceiling)
		free(data->ceiling);
	free(data);
}
