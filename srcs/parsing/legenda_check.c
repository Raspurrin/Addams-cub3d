#include "../../includes/cub3d.h"

/**
 * Extracting the string for the colour of the ceiling or the floor
 * and converting it to a usable integer.
 * @param colour_str example: "220,100,0"
 */
void	extract_colour(t_data *data, char *colour_str, t_colour *colour)
{
	size_t	i;
	size_t	channel_count;
	int32_t	colour_int;
	char	**channels;

	i = 3;
	channels = ft_split(colour_str, ',');
	channel_count = ft_2darrlen(channels);
	if (channel_count > 4 || channel_count < 3)
		errno(COLOUR, "", data);
	while (i > 0 && *colour_str)
	{
		colour_int = ft_atoi(*channels);
		if (colour_int < 0 || colour_int > 255)
			errno(COLOUR, "", data);
		colour->abgr[i] = (int8_t)colour_int;
		colour_str += (ft_strclen(colour_str, ',') + 1);
		channels++;
		i--;
	}
}

static void	legenda_innit(t_data *data, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(data->mlx, path, \
						&texture->width, &texture->height);
	if (!texture->img)
		errno(TEXTURE, path, data);
}

static void	legenda_check(t_data *data, t_legenda *legenda, \
										char *word, char *path)
{
	if (!legenda->ceiling && ft_strcmp(word, "C") == 0)
	{
		legenda->ceiling = malloc(sizeof(t_colour));
		extract_colour(data, path, legenda->ceiling);
	}
	else if (!legenda->floor && ft_strcmp(word, "F") == 0)
	{
		legenda->floor = malloc(sizeof(t_colour));
		extract_colour(data, path, legenda->floor);
	}
	else if (!legenda->north->img && ft_strcmp(word, "NO") == 0)
		legenda_innit(data, legenda->north, path);
	else if (!legenda->south->img && ft_strcmp(word, "SO") == 0)
		legenda_innit(data, legenda->south, path);
	else if (!legenda->west->img && ft_strcmp(word, "WE") == 0)
		legenda_innit(data, legenda->west, path);
	else if (!legenda->east->img && ft_strcmp(word, "EA") == 0)
		legenda_innit(data, legenda->east, path);
	else
		errno(INV_CHAR, "", data);
}

static void	direction_check(t_data *data, t_legenda *legenda, char **file)
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
	legenda_check(data, legenda, word, path);
	*file += ft_strlen(path);
}

void	element_check(t_data *data, char **file)
{
	size_t	i;

	i = 0;
	while (i < 6 && *file && **file)
	{
		direction_check(data, &data->legenda, file);
		i++;
	}
}
