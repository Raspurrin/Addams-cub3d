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

	vector.x = first.x + second.x;
	vector.y = first.y + second.y;
	return (vector);
}

t_vector	vector_multpl(t_vector first, t_vector second)
{
	t_vector	vector;

	vector.x = (first.x * second.x) - (first.y * second.y);
	vector.y = 2 * (first.x * second.y);
	return (vector);
}

t_vector rotatevectorlol(t_vector vct, int angle)
{
	t_vector tmp;

	tmp.x = vct.x;
	tmp.y = vct.y;
	vct.x = (tmp.x * cos(angle * M_PI/180)) - (tmp.y * sin(angle * M_PI/180));
	vct.y = (tmp.x * sin(angle * M_PI/180)) + (tmp.y * cos(angle * M_PI/180));
	return (vct);
}
