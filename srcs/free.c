/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:29 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:15:30 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_data(t_data *data)
{
	if (data->mlx)
		free(data->mlx);
	if (data->win)
		free(data->win);
}
	// if (data->map)
	// 	free_2d_guard(&data->map);
	// if (data.texture)
	// {
	// 	if (data.texture->north)
	// 		free(data.texture->north);
	// 	if (data.texture->south)
	// 		free(data.texture->south);
	// 	if (data.texture->west)
	// 		free(data.texture->west);
	// 	if (data.texture->east)
	// 		free(data.texture->east);
	// 	free(data.texture);
	// 	data.texture = NULL;
	// }
