/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 19:11:08 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_hex_fd(uint64_t nbr, int32_t fd)
{
	int32_t		i;
	const char	hexbase[] = "0123456789abcdef";

	i = 0;
	if (nbr == 0)
		i += ft_putchar_fd('0', fd);
	if (nbr >= 16)
	{
		i += ft_hex_fd(nbr / 16, fd);
		i += ft_hex_fd(nbr % 16, fd);
	}
	if (nbr < 16 && nbr != 0)
		i += ft_putchar_fd(hexbase[nbr], fd);
	return (i);
}
