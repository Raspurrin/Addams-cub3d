/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:19:57 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int32_t c)
{
	int32_t	len;
	char	*str2;

	len = ft_strlen((char *)str);
	str2 = (char *)str + len;
	if (!ft_isascii(c))
		return ((char *)str);
	while (len-- >= 0)
	{
		if (*str2 == c)
			return (str2);
		str2--;
	}
	return (0);
}
