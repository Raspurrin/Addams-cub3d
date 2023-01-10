#include "../../includes/cub3d.h"

bool	extension_check(char *map_name, char *ext)
{
	size_t	len;

	len = ft_strlen(map_name);
	while (len > 0 || map_name[len] != '.')
		len--;
	if (ft_strcmp(&map_name[len], ext) != 0)
		return (errno(INV_EXT, ""), false);
}
