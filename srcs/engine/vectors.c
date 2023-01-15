#include "../../includes/cub3d.h"

t_vector	vector_substr(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x - second.x;
	vector.y = first.y - second.y;
	return (vector);
}

t_vector	vector_add(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = first.x - second.x;
	vector.y = first.y - second.y;
	return (vector);
}

t_vector	vector_multpl(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = (first.x * second.x) - (first.y * second.y);
	vector.y = 2 * (first.x * second.y);
	return (vector);
}