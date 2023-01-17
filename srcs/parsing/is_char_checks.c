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

bool	is_player(t_player *player, char c, int32_t x, int32_t y)
{
	if (c != 'N' && c != 'E' && c != 'O' && c != 'W')
		return (false);
	player->pos.x = x * TILE;
	player->pos.y = y * TILE;
	if (c == 'N')
		player->dir.y = -100;
	if (c == 'S')
		player->dir.y = 100;
	if (c == 'E')
		player->dir.x = 100;
	if (c == 'W')
		player->dir.x = -100;
	return (true);
}
