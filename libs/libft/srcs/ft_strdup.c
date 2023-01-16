/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:19:02 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/10 20:48:49 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*out;

	len = ft_strlen((char *)str) + 1;
	out = ft_calloc(len + 1, sizeof(char));
	if (!out)
		return (NULL);
	ft_memcpy(out, str, len);
	return (out);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char name[] = "test";
// 	char *dst;
// 	dst = ft_strdup(name);
// 	printf("%s", dst);
// }
