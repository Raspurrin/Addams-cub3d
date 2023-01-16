/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:21:21 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/28 18:58:03 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

float	ft_log(int32_t base, int32_t nbr)
{
	size_t	i;

	i = 0;
	while (ft_pow(base, i) < nbr)
		i++;
}
