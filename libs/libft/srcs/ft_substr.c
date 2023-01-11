/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:20:13 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/10 20:05:37 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *str, uint32_t start, size_t len)
{
	char	*out;
	size_t	slen;

	slen = ft_strlen(str);
	if (!str)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		return (ft_strdup(str + start));
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, str + start, len);
	out[len] = '\0';
	return (out);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	dst[10];
// 	static char	dst2[10];
// 	char	src[] = "hgiello";
// 	char	src2[] = "lolk";
// 	printf("before: %s\n", dst);
// 	ft_substr(dst, src, 8);
// 	printf("after: %s\n", dst);
// 	// printf("before: %s\n", dst2);
// 	// ft_strlcpy(dst2, src, 8);
// 	// printf("after: %s\n", dst2);
// 	// printf("before: %s\n", dst2);
// 	// ft_strlcpy(dst2, src + 2, 8);
// 	// printf("after: %s\n", dst2);
// 	// printf("before: %s\n", dst2);
// 	// ft_strlcpy(dst2, dst2 + 2, 8);
// 	// printf("after: %s\n", dst2);
// 	return (0);
// }