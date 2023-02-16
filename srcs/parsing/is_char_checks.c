/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_char_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:14:44 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 02:14:26 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

bool	is_space_or_1(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || \
		c == '\v' || c == '\f' || c == '\r' || c == '1')
		return (true);
	return (false);
}

bool	is_valid_char(char c)
{
	if (ft_isspace(c) || c == '0' || c == '1' || c == 'N' || \
		c == 'E' || c == 'O' || c == 'W')
		return (true);
	return (false);
}

bool	is_player(t_data *data, t_player *player, int32_t x, int32_t y)
{
	if (data->map[y][x] != 'N' && data->map[y][x] != 'E' \
	&& data->map[y][x] != 'O' && data->map[y][x] != 'W')
		return (false);
	player->pos.x = x * TILE + (TILE / 2);
	player->pos.y = y * TILE + (TILE / 2);
	if (data->map[y][x] == 'N')
		player->dir.y = -1 * TILE / 4;
	if (data->map[y][x] == 'S')
		player->dir.y = TILE / 4;
	if (data->map[y][x] == 'E')
		player->dir.x = TILE / 4;
	if (data->map[y][x] == 'W')
		player->dir.x = -1 * TILE / 4;
	data->map[y][x] = '0';
	return (true);
}
