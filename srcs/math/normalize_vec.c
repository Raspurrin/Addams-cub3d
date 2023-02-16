#include "../../includes/cub3d.h"

t_vector	normalize_vec(t_vector vec)
{
	t_vector	out;
	double		length;

	length = sqrt(vec.x * vec.x + vec.y * vec.y);
	out.x = vec.x / length;
	out.y = vec.y / length;
	return (out);
}
