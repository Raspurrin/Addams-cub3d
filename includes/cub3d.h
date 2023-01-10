#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include "../libs/mlx/mlx.h"

typedef enum errno
{
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

#endif
