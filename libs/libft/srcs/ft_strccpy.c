#include "../includes/libft.h"

size_t	ft_strccpy(char *dst, const char *src, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strclen(src, c);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}
