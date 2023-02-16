#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <math.h>
# include "../libs/libft/includes/libft.h"
# include "../includes/engine.h"

# define VIEW_PORT 
# define SCREEN_WIDTH 1280
# define WIDTH_FOR_CEDRIC SCREEN_WIDTH
# define SCREEN_HEIGHT 720
// # define WIDTH_FOR_CEDRIC 720
# define TILE 100
# define FOV 90
# define RAY_COUNT WIDTH_FOR_CEDRIC

# define DIR_VECTOR TILE / 4
/* This is the distance you want to keep the player from the wall */
# define BOUNDARY 10

# define BUFFERSIZE 20

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define RED_CROSS 17
# define MOUSE_MOVE 6
# define MOUSE_DOWN 4

# if __linux__

#  include "../libs/minilibx-linux/mlx.h"
#  define ESC 65307
#  define ZOOM_IN 105
#  define ZOOM_OUT 111
#  define ARROW_UP 65362
#  define ARROW_DWN 65364
#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define SCROLL_DOWN 4
#  define SCROLL_UP 5
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 3
#  define MIDDLE_CLICK 2
#  define PLUS 112
#  define MINUS 109
#  define W_KEY 25
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2

# elif __APPLE__

#  include "../libs/mlx/mlx.h"
#  define ESC 53
#  define ZOOM_IN 34
#  define ZOOM_OUT 31
#  define ARROW_UP 126
#  define ARROW_DWN 125
#  define ARROW_LEFT 123
#  define SCROLL_DOWN 5
#  define SCROLL_UP 4
#  define LEFT_CLICK 1
#  define RIGHT_CLICK 2
#  define MIDDLE_CLICK 3
#  define ARROW_RIGHT 124
#  define W_KEY 13
#  define A_KEY 0
#  define S_KEY 1
#  define D_KEY 2

// movement bool:
# define UP 1
# define DOWN 2
# define LEFT 4
# define RIGHT 8

# endif



typedef enum errno
{
	ARGS,
	READ_FAIL,
	COLOUR,
	NO_CUB,
	INV_CHAR,
	INV_EXT,
	INV_MAP,
	TEXTURE,
	PLAYERS,
	NOPLAYER
}	t_errno;

typedef enum temp_textures
{
	NORTH,
	WEST,
	SOUTH,
	EAST,
	TEXTCOUNT
}	t_temp_textures;

typedef union s_colour
{
	uint32_t	bgra_i;
	uint8_t		bgra[4];
	struct
	{
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
		uint8_t	a;
	};
}	t_colour;


typedef struct s_intvector
{
	int32_t	x;
	int32_t	y;
}	t_intvector;

typedef struct s_player
{
	uint32_t	movement;
	t_vector	dir;
	t_vector	pos;
}	t_player;

typedef struct s_texture
{
	t_img	*img;
	int32_t	width;
	int32_t	height;
}	t_texture;

typedef struct	s_ratio
{
	int32_t	interval;
	int32_t	repeat;
}	t_ratio;

typedef struct s_wall
{
	t_vector	pos;
	double		distance;
	int32_t		direction;
	uint32_t	height;
	uint32_t	offset;
}	t_wall;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_player	player;
	int32_t		map_width;
	int32_t		map_height;
	t_vector	mid_canvas;
	t_texture	canvas;
	t_texture	texture[TEXTCOUNT];
	t_colour	*floor;
	t_colour	*ceiling;
	t_colour	colour;
	t_vector	vector;
	t_wall		wall;
}	t_data;

/* vector */
t_vector	normalize_vec(t_vector vec);

void	ray_the_caster(t_data *data);

/* general functions */
void	init(t_data *data);
void	free_data(t_data *data);
void	errno(int8_t nbr, char *msg, t_data *data);

/* mlx */
void	move(t_data *data, int32_t movement);
void	key_hooks(t_data *data);
int		x_close(t_data *data);
int		move_on_press(int keycode, t_data *data);
int		move_on_release(int keycode, t_data *data);
void	check_mouse_movement(t_data *data);

/* parsing */
char	*read_file(int32_t fd);
void	error_check(t_data *data, int32_t argc, char **argv);
void	extract_map(t_data *data, char *file);
void	element_check(t_data *data, char **file);
void	init_texture(t_data *data, t_texture *texture, char *path);
bool	is_space_or_1(char c);
bool	is_valid_char(char c);
bool	is_player(t_data *data, t_player *player, int32_t x, int32_t y);
void	fill_str(char *str, size_t start, size_t end, char c);
int32_t	count_newlines_end(char *file);
int32_t	count_newlines_start(char *file);

/* graphics */
void	draw_textures(t_data *data);
int32_t	rgb_to_int(int32_t r, int32_t g, int32_t b, int32_t a);
int32_t	add_channel(int32_t colour, int32_t channel, int8_t bitshift);
void	print_bits(int32_t nbr);
void	init_image(t_data *data, t_img *img);
int32_t	rev_colour(t_colour *colour);

t_vector get_init_pos(t_player playa);
int				game_loop(void *data2);
double	vec_dot(t_vector one, t_vector two);
unsigned int	my_mlx_pixel_get(t_texture *texture, int x, int y);
void	draw_vertical_line(t_data *data, t_texture *texture, t_wall *wall, t_intvector draw);
double get_next_angle(t_vector ini, t_player playa, int ray);
#endif
