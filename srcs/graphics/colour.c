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
int32_t	argb_to_int(int32_t a, int32_t r, int32_t g, int32_t b)
{
	return (a << 24 | b << 16 | g << 8 | r);
}

/* this approach doensn't seem to work .-. Help */
int32_t	rev_colour(t_colour *colour)
{
	t_colour	temp;

	temp = *colour;
	(*colour).a = temp.b;
	(*colour).r = temp.g;
	(*colour).g = temp.r;
	(*colour).b = temp.a;

	return ((*colour).bgra_i);
}

int32_t	add_channel(int32_t colour, int32_t channel, int8_t bitshift)
{
	return (channel << bitshift | colour);
}

void	print_bits(int32_t nbr)
{
	size_t	i;

	i = 32;
	while (i > 0)
	{
		if (((nbr >> i) & 1) == 1)
			write(STDOUT_FILENO, "1", 1);
		else
			write(STDOUT_FILENO, "0", 1);
		i--;
	}
}
