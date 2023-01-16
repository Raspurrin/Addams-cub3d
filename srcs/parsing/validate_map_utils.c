#include "../../includes/cub3d.h"

void	fill_str(char *str, size_t start, size_t end, char c)
{
	size_t	i;

	i = start;
	while (i < end)
		str[i++] = c;
	str[i] = '\0';
}

/**
 * @brief counting newlines at the end of the file to adjust the mapheight
 * in largest_row()
 */
int32_t	count_newlines_end(char *file)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = ft_strlen(file);
	while (i >= 0 && file[i] == '\n')
	{
		count++;
		i--;
	}
	return (count);
}

int32_t	count_newlines_start(char *file)
{
	size_t	count;

	count = 0;
	while (*file && ft_isspace(*file))
	{
		if (*file == '\n')
			count++;
		file++;
	}
	return (count);
}
