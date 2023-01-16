/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2d_guard.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:49:55 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	free_2d_guard(char ***arr)
{
	size_t	i;

	i = 0;
	if (*arr)
	{
		while (*(arr) && (*arr)[i])
		{
			free((*arr)[i]);
			(*arr)[i++] = NULL;
		}
		free(*arr);
		*arr = NULL;
	}
}
