/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:38 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 12:30:15 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int32_t	main(int argc, char *argv[])
{
	t_data	data;

	init(&data);
	init_image(&data, data.canvas.img);
	mlx_mouse_hide();
	data.texture->height = 0;
	data.texture->width = 0;
	error_check(&data, argc, argv);
	data.canvas.height = data.map_height * TILE;
	data.canvas.width = data.map_width * TILE;
	data.mid_canvas.x = SCREEN_WIDTH / 2;
	data.mid_canvas.y = SCREEN_HEIGHT / 2;
	mlx_loop_hook(data.mlx, game_loop, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
