#include "../../includes/cub3d.h"

bool	is_wall(t_data *data, t_vector pos)
{
	int	x;
	int	y;

	x = pos.y / 100;
	y = pos.x / 100;
	if (x < 0 || y < 0 || y > data->map_width - 1 || x > data->map_height - 1)
	{
		printf("SZTOPPPPPPPP!!!!!!!!, because x is %d,,,, and y is %i\n", y, x);
		exit(1);
	}
	if (data->map[x][y] != '0')
		return (true);
	return (!true);
}
