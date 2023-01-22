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

# define A_VERY_VERY_BIG_NUMMER 1000000000000000000

typedef struct s_vector t_vector;
typedef struct s_data	t_data;

typedef struct s_img
{
	void	*img_ptr;
	void	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

/* mlx */
void		my_mlx_pixel_put(t_img *data, int x, int y, int color);
// int		get_colour(t_colour colour);
/* hooks */
int			x_close(t_data *data);
int			key_handler(int keycode, t_data *data);
/* move */
void		move(t_data *data, bool up, bool dwn, bool rht, bool lft);
/* render stuff */
void		draw_player(t_data *data);
void		draw_the_grid(t_data *data);
void		ray_the_caster(t_data *data);
void		draw_background(t_data *data);
void		draw_addams_cube(t_data *data);
void		draw_the_walls(t_data *data, int x, int y, bool wall);
void		draw_line_img(t_img *img, t_vector eins, t_vector zwei, int color);
/* vector */
t_vector	vector_add(t_vector first, t_vector second);
t_vector	vector_multpl(t_vector first, t_vector second);
t_vector	vector_substr(t_vector first, t_vector second);
t_vector	rotatevectorlol(t_vector vct, double angle); //do not rename!!!!!!!
/*  */
bool		is_wall(t_data *data, t_vector pos);
double		horizontal_raycast(t_data *data, t_vector direction);
double		vertikal_raycast(t_data *data, t_vector direction);

double		just_abs(double i);

double		calc_the_theorem(t_vector vect);




#endif