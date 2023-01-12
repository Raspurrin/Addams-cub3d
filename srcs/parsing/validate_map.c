#include "../../includes/cub3d.h"

// not sure if we are gonna need this
static void	fill_str(char *str, size_t start, size_t end, char c)
{
	size_t	i;

	i = start;
	while (i < end)
		str[i++] = c;
	str[i] = '\0';
}

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
		file += row_len;
		data->map_height++;
	}
	data->map_width = largest_row;
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

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		while (x < data->map_width)
		{
			if ((x == 0 || x == data->map_width - 1 || y == 0 \
			|| y == data->map_height - 1))
			{
				if (!is_space_or_1(map[y][x]))
					errno(INV_MAP, "", data);
			}
			else if (ft_isspace(map[y][x]))
			{
				if (!is_space_or_1(map[y + 1][x]) || !is_space_or_1(map[y - 1][x]) || \
					!is_space_or_1(map[y][x - 1]) || !is_space_or_1(map[y][x + 1]))
					errno(INV_MAP, "", data);
			}
			else if (!is_valid_char(map[y][x]))
				errno(INV_MAP, "", data);
			x++;
		}
		x = 0;
		y++;
	}
}

void	extract_map(t_data *data, char *file)
{
	size_t	i;
	size_t	row_length;

	i = 0;
	while (ft_isspace(file[i]))
	{
		if (file[i] == '\n')
		{
			file += (i + 1);
			i = 0;
		}
		i++;
	}
	i = 0;
	largest_row(data, file);
	data->map = ft_calloc(data->map_height, sizeof(char *));
	while (i < (size_t)data->map_height)
	{
		data->map[i] = ft_calloc(data->map_width + 1, sizeof(char));
		row_length = ft_strccpy(data->map[i], file, '\n');
		fill_str(data->map[i], row_length - 1, data->map_width, ' ');
		file += row_length;
		i++;
	}
	mapcheck(data, data->map);
}
