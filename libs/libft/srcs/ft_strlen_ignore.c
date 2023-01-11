/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_ignore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:06:24 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/17 21:14:34 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strlen_ignore(const char *str, char ignore)
{
	int32_t	i;
	int32_t	minus;

	i = 0;
	minus = 0;
	while (str[i] != '\0')
	{
		if (str[i++] == ignore)
			minus++;
	}
	return (i - minus);
}
