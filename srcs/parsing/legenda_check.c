#include "../../includes/cub3d.h"

/**
 * Extracting the string for the colour of the ceiling or the floor
 * and converting it to a usable integer.
 * @param colour_str example: "220,100,0"
 */
void	extract_colour(t_data *data, char *colour_str, t_colour *colour)
{
	size_t	i;
	int32_t	colour_int;
	char	*channel_str;

	i = 3;
	while (i > 0 && *colour_str)
	{
		channel_str = ft_subcstr(colour_str, ',');
		colour_int = ft_atoi(channel_str);
		free(channel_str);
		if (colour_int < 0 || colour_int > 255)
			errno(COLOUR, "", data);
		colour->abgr[i] = (int8_t)colour_int;
		colour_str += (ft_strclen(colour_str, ',') + 1);
		i--;
	}
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
		errno(INV_CHAR, "", data);
	*file += len;
	path = skip_spaces(file);
	if (!texture->ceiling && ft_strcmp(word, "C") == 0)
	{
		texture->ceiling = malloc(sizeof(t_colour));
		extract_colour(data, path, texture->ceiling);
	}
	else if (!texture->floor && ft_strcmp(word, "F") == 0)
	{
		texture->floor = malloc(sizeof(t_colour));
		extract_colour(data, path, texture->floor);
	}
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

void	element_check(t_data *data, char **file)
{
	size_t	i;

	i = 0;
	while (i < 6 && *file && **file)
	{
		direction_check(data, &data->texture, file);
		i++;
	}
}
