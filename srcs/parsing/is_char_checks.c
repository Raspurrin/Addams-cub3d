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
	player->pos.x = x * TILE;
	player->pos.y = y * TILE;
	if (data->map[y][x] == 'N')
		player->dir.y = -1 * DIR_VECTOR;
	if (data->map[y][x] == 'S')
		player->dir.y =  DIR_VECTOR;
	if (data->map[y][x] == 'E')
		player->dir.x =  DIR_VECTOR;
	if (data->map[y][x] == 'W')
		player->dir.x = -1 * DIR_VECTOR;
	data->map[y][x] = '0';
	return (true);
}
