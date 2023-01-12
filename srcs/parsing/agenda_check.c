#include "../../includes/cub3d.h"

/**
 * Extracting the string for the colour of the ceiling or the floor
 * and converting it to a usable integer.
 * @param colour_str example: "220,100,0"
 */
int32_t	extract_colour(t_data *data, char *colour_str)
{
	char	*channel_str;
	int32_t	channel_nbr;
	int32_t	bitshift;
	int32_t	colour;

	colour = 0;
	bitshift = 0;
	while (*colour_str)
	{
		channel_str = ft_subcstr(colour_str, ',');
		channel_nbr = ft_atoi(channel_str);
		if (channel_nbr < 0 || channel_nbr > 255)
			return (free(channel_str), errno(COLOUR, "", data), 0);
		colour = add_channel(colour, ft_atoi(channel_str), bitshift);
		free(channel_str);
		bitshift += 8;
		colour_str += (ft_strclen(colour_str, ',') + 1);
	}
	return (colour);
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

void	element_check(t_data *data, char **file)
{
	size_t	i;

	i = 0;
	while (i < 6)
	{
		direction_check(data, &data->texture, file);
		i++;
	}
}
