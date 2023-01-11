/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 02:41:58 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/20 02:42:09 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

void	*ft_realloc_n(void *ptr, size_t size, size_t ptr_len)
{
	size_t	i;
	char	*out;

	i = 0;
	if (!ptr)
		return (NULL);
	out = malloc(size);
	if (!out)
		return (NULL);
	while (ptr_len-- > 0)
	{
		out[i] = ((uint8_t *)ptr)[i];
		i++;
	}
	free(ptr);
	return (out);
}
