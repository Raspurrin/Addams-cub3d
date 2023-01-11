/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 00:40:29 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/21 00:52:52 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	if (ft_strlen(str1) != ft_strlen(str2))
		return (-1);
	while ((uint8_t)str1[i] && (uint8_t)str2[i] && \
			(uint8_t)str1[i] == (uint8_t)str2[i])
		i++;
	return ((uint8_t)str1[i] - (uint8_t)str2[i]);
}
