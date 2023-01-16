/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:10:48 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int32_t nbr)
{
	char	*out;
	size_t	i;

	i = ft_intlen(nbr);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	out = malloc(i + 1 * sizeof(char));
	if (nbr == 0)
		out[0] = '0';
	else if (nbr < 0)
	{
		out[0] = '-';
		nbr = ft_abs(nbr);
	}
	out[i--] = '\0';
	while (nbr > 0)
	{
		out[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (out);
}
