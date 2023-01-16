/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 01:44:38 by mialbert          #+#    #+#             */
/*   Updated: 2022/08/03 01:45:57 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	binary_count(size_t lst_size)
{
	size_t	bin_count;

	bin_count = 0;
	while (lst_size)
	{
		lst_size >>= 1;
		bin_count++;
	}
	return (bin_count);
}
