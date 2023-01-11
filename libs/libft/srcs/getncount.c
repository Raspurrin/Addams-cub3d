/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getncount.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:41:06 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	getncount(char *str, uint8_t n)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == n)
			count++;
		str++;
	}
	return (count);
}
