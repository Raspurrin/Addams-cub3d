#ifndef ENGINE_H
# define ENGINE_H
# define RESET		"\033[0m"
# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define PURPLE		"\033[0;34m"
# define PINK		"\033[0;35m"
# define SKY		"\033[0;36m"

# define ON_RED 	"\033[41m"
# define ON_PURPLE	"\033[44m"
# define ON_PINK	"\033[45m"

typedef struct s_vector t_vector;
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

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_player
{
	int			x;
	int			y;
	t_vector	direction;
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
/* vector */
t_vector	vector_multpl(t_vector first, t_vector second);
t_vector	vector_substr(t_vector first, t_vector second);
t_vector	vector_add(t_vector first, t_vector second);

void	draw_the_ray(t_data *data);


#endif