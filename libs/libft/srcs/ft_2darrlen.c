#include "../includes/libft.h"

size_t	ft_2darrlen(char **arr)
{
	size_t	count;

	count = 0;
	while (arr[count])
		count++;
	return (count);
}
