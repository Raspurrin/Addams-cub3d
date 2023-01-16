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
int32_t	count_newlines(char *file)
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
