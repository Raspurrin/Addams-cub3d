/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_str2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:11:44 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/21 19:15:23 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_str2(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;
	char	*out;

	if (!str1 || !str2)
		return (0);
	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	out = ft_calloc((str1len + str2len + 1), sizeof(char));
	if (!out)
		return (0);
	ft_strlcpy(out, str1, str1len + 1);
	ft_strlcpy(out + str1len, str2, str2len + 1);
	free(str2);
	return (out);
}
