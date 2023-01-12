#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include "../libs/mlx/mlx.h"
# include "../libs/libft/includes/libft.h"

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 500

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

# endif

typedef enum errno
{
	ARGS,
	READ_FAIL,
	NO_CUB,
	INV_CHAR,
	INV_EXT,
	INV_MAP,
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
	char	*floor;
	char	*ceiling;
}	t_texture;

typedef struct data
{
	void		*mlx;
	void		*win;
	char		**map;
	int32_t		map_width;
	int32_t		map_height;
	t_texture	texture;
}	t_data;

/* general functions */
void	errno(int8_t nbr, char *msg, t_data *data);
void	free_data(t_data *data);
void	error_checking(t_data *data, int32_t argc, char **argv);

/* mlx */
void	key_hooks(t_data *data);

/* parsing */
void	init(t_data *data);
void	extract_map(t_data *data, char *file);
char	*read_file(int32_t fd);
bool	is_space_or_1(char c);
bool	is_valid_char(char c);

#endif
