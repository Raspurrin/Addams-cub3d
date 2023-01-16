#include "../includes/libft.h"

char	*ft_subcstr(char *src, char c)
{
	size_t	i;
	size_t	len;
	char	*dst;

	i = 0;
	len = ft_strclen(src, c);
	dst = malloc(len * sizeof(char) + 1);
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
