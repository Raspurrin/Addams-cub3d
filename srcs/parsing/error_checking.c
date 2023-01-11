#include "../../includes/cub3d.h"

static void	extension_check(t_data *data, char *map_name, char *ext)
{
	size_t	len;

	len = ft_strlen(map_name);
	while (len > 0 || map_name[len] != '.')
		len--;
	if (ft_strcmp(&map_name[len], ext) != 0)
		return (errno(INV_EXT, "", data));
}

static char	*skip_spaces(char **file)
{
	size_t	end;

	end = 0;
	while (ft_isspace(**file))
		(*file)++;
	while (ft_isascii(*file[end]))
		end++;
	return (ft_substr(*file, 0, end));
}

static void	direction_check(t_data *data, t_texture *texture, char **file)
{
	size_t	len;
	char	*word;

	word = skip_spaces(file);
	len = ft_strlen(word);
	if (len < 1 || len > 2)
		return (errno(INV_CHAR, "", data));
	*file += len;
	if (!texture->ceiling && ft_strcmp(word, "C"))
		texture->ceiling = skip_spaces(file);
	else if (!texture->floor && ft_strcmp(word, "F"))
		texture->floor = skip_spaces(file);
	else if (!texture->north && ft_strcmp(word, "NO"))
		texture->north = skip_spaces(file);
	else if (!texture->south && ft_strcmp(word, "SO"))
		texture->south = skip_spaces(file);
	else if (!texture->west && ft_strcmp(word, "WE"))
		texture->west = skip_spaces(file);
	else if (!texture->east && ft_strcmp(word, "EA"))
		texture->east = skip_spaces(file);
	else
		errno(INV_CHAR, "", data);
	file += len;
}

static void	element_check(t_data *data, char **file)
{
	size_t	i;

	i = 0;
	while (i < 6)
	{
		direction_check(data, data->texture, file);
		i++;
	}
}

void	error_checking(t_data *data, int32_t argc, char **argv)
{
	int32_t	fd;
	char	*file;

	if (argc > 2)
		return (errno(ARGS, "", data), false);
	if (argc <= 1)
		return (errno(NO_CUB, "", data), false);
	extension_check(data, argv[1], ".cub");
	fd = open(argv[1]);
	file = read_file(fd);
	element_check(data, &file);
	extract_map(data, file);
}
