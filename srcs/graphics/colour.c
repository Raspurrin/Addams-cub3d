#include "../../includes/cub3d.h"

/**
 * g 		10010001 00000000 0000000 0000000 >> 8
 * g		00000000 10010001 0000000 0000000 OR
 * colour	11110001 00000000 0000000 0000000 
 * --------------------------------------------
 * result	11110001 10010001 0000000 0000000
 * 
 * @return int32_t 
 */
int32_t	rgb_to_int(int32_t r, int32_t g, int32_t b, int32_t a)
{
	int32_t	colour;

	colour = 0;
	colour = r >> 0 | colour;
	colour = g >> 8 | colour;
	colour = b >> 16 | colour;
	colour = a >> 24 | colour;
	return (colour);
}

int32_t	add_channel(int32_t colour, int32_t channel, int8_t bitshift)
{
	return (channel >> bitshift | colour);
}

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
