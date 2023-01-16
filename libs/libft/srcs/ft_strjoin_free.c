/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:38:52 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/21 11:43:20 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin_free(char *str1, char *str2)
{
	size_t	str1len;
	size_t	str2len;
	char	*out;

	if (!str1 || !str2)
		return (0);
	str1len = gnl_strlen(str1);
	str2len = gnl_strlen(str2);
	out = malloc((str1len + str2len + 1) * sizeof(char));
	if (!out)
		return (0);
	gnl_strlcpy(out, str1, str1len + 1);
	free(str1);
	gnl_strlcpy(out + str1len, str2, str2len + 1);
	free(str2);
	return (out);
}
