#include "../../includes/cub3d.h"

/**
 * Reads the map into one big ass string directly with the read 
 * function instead of GNL to avoid memory fuckery and having it 
 * initialised instead of reading repeatedly is more efficient.
 * Later on store it in a 2D array for easy error checking
 * and data checking during the game loop. 
 */
char	*read_file(int32_t fd)
{
	int32_t	buflen;
	char	*line;
	char	*buf;

	buflen = 1;
	line = ft_calloc(1, 1);
	buf = malloc(BUFFERSIZE + 1 * sizeof(char));
	while (buflen > 0)
	{
		buflen = read(fd, buf, BUFFERSIZE);
		if (buflen <= 0)
			free (buf);
		if (buflen == 0)
			return (line);
		if (buflen < 0)
			return (NULL);
		buf[buflen] = '\0';
		line = gnl_strjoin(line, buf);
	}
	close(fd);
	return (line);
}
