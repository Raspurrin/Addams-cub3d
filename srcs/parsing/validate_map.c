#include "../../includes/cub3d.h"

static void	largest_row(t_data *data, char *file)
{
	size_t	row_len;
	size_t	largest_row;

	row_len = 0;
	largest_row = 0;
	while (*file)
	{
		row_len = ft_strclen(file, '\n');
		if (row_len > largest_row)
			largest_row = row_len;
		file += (row_len + 1);
		data->map_height++;
	}
	data->map_width = largest_row;
}

static bool	around_space_valid(t_data *data, char **map, int32_t x, int32_t y)
{
	if (ft_isspace(map[y][x]))
	{
		if ((y != data->map_height - 1 && !is_space_or_1(map[y + 1][x])) || \
		(y != 0 && !is_space_or_1(map[y - 1][x])) || \
		(x != 0 && !is_space_or_1(map[y][x - 1])) || \
		(x != data->map_width - 1 && !is_space_or_1(map[y][x + 1])))
			return (false);
	}
	return (true);
}

/**
 * If there is anything but a 1 or space neighbouring a space, the map is not
 * enclosed and returns an error. Also checks for invalid characters in the map.
 * @param data 
 * @param map 
 */
static void	mapcheck(t_data *data, char **map)
{
	int32_t	x;
	int32_t	y;
	int8_t	player;

	x = 0;
	y = 0;
	player = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			if (!is_valid_char(map[y][x]))
				errno(INV_CHAR, "", data);
			if (!around_space_valid(data, map, x, y))
				errno(INV_MAP, "", data);
			if (is_player(&data->player, map[y][x], x, y))
				player++;
			if (player > 1)
				errno(PLAYERS, "", data);
			x++;
		}
		x = 0;
		y++;
	}
	if (player < 1)
		errno(NOPLAYER, "", data);
}

void	extract_map(t_data *data, char *file)
{
	size_t	i;
	size_t	row_length;

	i = 0;
	file += count_newlines_start(file);
	largest_row(data, file);
	data->map_height -= count_newlines_end(file);
	data->map = ft_calloc(data->map_height, sizeof(char *));
	while (i < (size_t)data->map_height)
	{
		data->map[i] = ft_calloc(data->map_width + 1, sizeof(char));
		row_length = ft_strccpy(data->map[i], file, '\n');
		fill_str(data->map[i], row_length, data->map_width, ' ');
		file += row_length + 1;
		i++;
	}
	mapcheck(data, data->map);
}
