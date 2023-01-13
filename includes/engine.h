#ifndef ENGINE_H
# define ENGINE_H

typedef struct data	t_data;

typedef struct s_img
{
	void	*img_ptr;
	void	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_colour
{
	int	t;
	int	r;
	int	g;
	int	b;
}	t_colour;

typedef struct s_player
{
	int x;
	int	y;
}	t_player;
// yes
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

//
void	draw_addams_cube(t_data *data);

// hooks 
int	key_handler(int keycode, t_data *data);
int	x_close(t_data *data);

int	get_colour(t_colour colour);
void	move_up(t_data *data);


#endif