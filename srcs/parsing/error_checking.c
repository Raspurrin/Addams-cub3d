#include "../../includes/cub3d.h"

static void	extension_check(t_data *data, char *map_name, char *ext)
{
	size_t	len;

	len = ft_strlen(map_name);
	while (len > 0)
	{
		if (map_name[len] == '.')
			break ;
		len--;
	}
	if (ft_strcmp(&map_name[len], ext) != 0)
		return (errno(INV_EXT, "", data));
}

static char	*skip_spaces(char **file)
{
	size_t	end;

	end = 0;
	while (ft_isspace(**file))
		(*file)++;
	while (!ft_isspace((*file)[end]))
		end++;
	return (ft_substr(*file, 0, end));
}

static void	direction_check(t_data *data, t_texture *texture, char **file)
{
	size_t	len;
	char	*word;
	char	*path;

	word = skip_spaces(file);
	len = ft_strlen(word);
	if (len < 1 || len > 2)
		return (errno(INV_CHAR, "", data));
	*file += len;
	path = skip_spaces(file);
	if (!texture->ceiling && ft_strcmp(word, "C") == 0)
		texture->ceiling = extract_colour(data, path);
	else if (!texture->floor && ft_strcmp(word, "F") == 0)
		texture->floor = extract_colour(data, path);
	else if (!texture->north && ft_strcmp(word, "NO") == 0)
		texture->north = ft_strdup(path);
	else if (!texture->south && ft_strcmp(word, "SO") == 0)
		texture->south = ft_strdup(path);
	else if (!texture->west && ft_strcmp(word, "WE") == 0)
		texture->west = ft_strdup(path);
	else if (!texture->east && ft_strcmp(word, "EA") == 0)
		texture->east = ft_strdup(path);
	else
		errno(INV_CHAR, "", data);
	*file += ft_strlen(path);
}

static void	element_check(t_data *data, char **file)
{
	size_t	i;

	i = 0;
	while (i < 6)
	{
		direction_check(data, &data->texture, file);
		i++;
	}
}

void	error_checking(t_data *data, int32_t argc, char **argv)
{
	int32_t	fd;
	char	*file;

	if (argc > 2)
		errno(ARGS, "", data);
	if (argc <= 1)
		errno(NO_CUB, "", data);
	extension_check(data, argv[1], ".cub");
	fd = open(argv[1], O_RDWR);
	file = read_file(fd);
	element_check(data, &file);
	extract_map(data, file);
}
