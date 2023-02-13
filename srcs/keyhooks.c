#include "../includes/cub3d.h"

void	move(t_data *data, int32_t movement)
{
	// tem vec
	t_vector temp;
	temp.x = data->player.dir.x * 0.3;
	temp.y = data->player.dir.y * 0.3;
	if (movement & UP &&  !is_wall(data, vector_add(data->player.pos, data->player.dir)))
		data->player.pos = vector_add(data->player.pos, temp);
	if (movement & DOWN && !is_wall(data, vector_substr(data->player.pos, data->player.dir)))
		data->player.pos = vector_substr(data->player.pos, temp);
	if (movement & RIGHT && !is_wall(data, vector_add(data->player.pos, rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_add(data->player.pos, rotatevectorlol(temp, 90));
	if (movement & LEFT && !is_wall(data, vector_substr(data->player.pos, rotatevectorlol(data->player.dir, 90))))
		data->player.pos = vector_substr(data->player.pos, rotatevectorlol(temp, 90));
	// check if tmp in wall
	// only if !wall update pos player
}

void	move_on_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		x_close(data);
	else if (keycode == W_KEY)
		data->player.movement = data->player.movement | UP; 
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement | DOWN; 
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement | RIGHT; 
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement | LEFT; 
	else if (keycode == ARROW_RIGHT)
		data->player.dir = rotatevectorlol(data->player.dir, 10);
	else if (keycode == ARROW_LEFT)
		data->player.dir = rotatevectorlol(data->player.dir, -10);
}

void	move_on_release(int keycode, t_data *data)
{
	if (keycode == W_KEY)
		data->player.movement = data->player.movement & ~UP; 
	else if (keycode == S_KEY)
		data->player.movement = data->player.movement & ~DOWN; 
	else if (keycode == D_KEY)
		data->player.movement = data->player.movement & ~RIGHT; 
	else if (keycode == A_KEY)
		data->player.movement = data->player.movement & ~LEFT; 
}

int	x_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}
