

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
# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"
# include "../includes/engine.h"

typedef struct data	t_data;
typedef struct s_vector t_vector;

# define SCREEN_WIDTH 2000
# define SCREEN_HEIGHT 1000

# define BUFFERSIZE 20

# define KEY_PRESS 2
# define RED_CROSS 17
# define MOUSE_MOVE 6
# define MOUSE_DOWN 4

# if __linux__

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

# elif __APPLE__

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


# endif

typedef enum errno
{
	ARGS,
	READ_FAIL,
	NO_CUB,
	INV_CHAR,
	INV_EXT,
	WALLS,
	SPACES,
	ORDER,
	TEXTURE,
	ELEMENT,
	COLOUR,
	INCOMPLETE
}	t_errno;

typedef struct texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int32_t	floor;
	int32_t	ceiling;
}	t_texture;

typedef struct data
{
	void		*mlx;
	void		*win;
	char		**map;
	int32_t		map_width;
	int32_t		map_height;
	int			player_x;
	int			player_y;
	t_texture	*texture;
	t_img		img;
	t_colour	colour;
	t_player	player;
	t_vector	vector;
}	t_data;

// /* general functions */
void	errno(int8_t nbr, char *msg, t_data *data);
// void	free_data(t_data *data);
// void	error_checking(t_data *data, int32_t argc, char **argv);

/* mlx */
void	key_hooks(t_data *data);

/* parsing */
void	extract_map(t_data *data, char *file);
char	*read_file(int32_t fd);

#endif

//13 w
//0 a
//1 s
//2	d