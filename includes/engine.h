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

/* mlx */
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int		get_colour(t_colour colour);
/* hooks */
int		key_handler(int keycode, t_data *data);
int		x_close(t_data *data);
/* move */
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	move_left(t_data *data);
/* render stuff */
void	draw_addams_cube(t_data *data);
void	draw_player(t_data *data);
void	draw_the_grid(t_data *data);
void	draw_background(t_data *data);
void	draw_the_walls(t_data *data, int x, int y, bool wall);


#endif