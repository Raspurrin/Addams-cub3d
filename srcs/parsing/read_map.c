#include "../../includes/cub3d.h"

/**
 * Reads the map into one big ass string directly with the read 
 * function instead of GNL to avoid memory fuckery and having it 
 * initialised instead of reading repeatedly is more efficient.
 * Later on store it in a 2D array for easy error checking
 * and data checking during the game loop. 
 */
char	*read_file(int32_t fd)
{
	int32_t	buflen;
	char	*line;
	char	*buf;

	buflen = 1;
	line = ft_calloc(1, 1);
	buf = malloc(BUFFERSIZE + 1 * sizeof(char));
	while (buflen > 0)
	{
		buflen = read(fd, buf, BUFFERSIZE);
		if (buflen <= 0)
			free (buf);
		if (buflen == 0)
			return (line);
		if (buflen < 0)
			return (NULL);
		buf[buflen] = '\0';
		line = gnl_strjoin(line, buf);
	}
	close(fd);
	return (line);
}

// not sure if we are gonna need this
// void	fill_str(char *str, size_t end, char c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < end)
// 		str[i++] = c;
// 	str[i] = '\0';
// }

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

// static void	mapcheck(t_data *data, char **map)
// {
// 	size_t	x;
// 	size_t	y;

// 	x = 0;
// 	y = 0;
// 	while (y < data->map_height)
// 	{
// 		while (x < data->map_width)
// 		{
// 			if (ft_isspace(map[y][x]))
// 				x++;
// 		}
// 		y++;
// 	}
// 	map_check(x, y);
// }

void	extract_map(t_data *data, char *file)
{
	size_t	i;
	size_t	row_length;
	char	*map_array;
	char	**map;

	i = 0;
	while (ft_isspace(file[i]))
	{
		if (file[i] == '\n')
		{
			file += i;
			i = 0;
		}
		i++;
	}
	i = 0;
	largest_row(file, data);
	map = ft_calloc(data->map_height, sizeof(char *));
	while (map[i])
	{
		map[i] = malloc(data->map_width * sizeof(char));
		row_length = ft_strccpy(map[i], file, '\n');
		file += row_length;
		i++;
	}
}
