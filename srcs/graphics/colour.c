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
