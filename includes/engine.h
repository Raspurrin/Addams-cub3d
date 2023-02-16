/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 02:07:45 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 02:44:39 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdbool.h>
# include <math.h>

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
// # define VECTORS t_vector yup, t_vector dir, t_vector first

typedef struct s_vecstack	t_vecstack;
typedef struct s_vector		t_vector;
typedef struct s_data		t_data;
typedef struct s_texture	t_texture;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_vecstack
{
	t_vector	yup;
	t_vector	strich;
	t_vector	first_inter;
}	t_vecstack;

/* mlx */
void		my_mlx_pixel_put(t_texture *data, int x, int y, int color);

/* hooks */
int			x_close(t_data *data);
int			key_handler(int keycode, t_data *data);

/* render stuff */
void		ray_the_caster(t_data *data);
void		draw_the_walls(t_data *data, int x, int y, bool wall);

/* vector */
t_vector	normalize_vec(t_vector vec);
t_vector	vector_add(t_vector first, t_vector second);
t_vector	vector_multpl(t_vector first, t_vector second);
t_vector	vector_substr(t_vector first, t_vector second);
t_vector	rotatevectorlol(t_vector vct, double angle); //do not rename!!!!!!!

/* functions that fix stuff */
bool		is_wall(t_data *data, t_vector pos);
double		horizontal_raycast(t_data *data, t_vector direction);
double		vertikal_raycast(t_data *data, t_vector direction);
double		calc_the_theorem(t_vector vect);
void		single_ray(t_data *data, t_vector direction);

/* useless_file_because_norminette */
int			end_condition(t_data *data, t_vector vector);
double		direction_check(t_data *data, t_vector direction, \
										double y, bool horiz);
double		ratio_is_actually_distance(t_data *data, double dist, \
										t_vector first, int cond);
t_vector	cond_horiz_zero(t_data *data, t_vecstack vec, \
								t_vector dir, double ratio);
t_vector	cond_vert_zero(t_data *data, t_vecstack vec, \
								t_vector dir, double ratio);
t_vector	dir_smoler_zero(t_vector direction, t_vector strich, bool horiz);

#endif
