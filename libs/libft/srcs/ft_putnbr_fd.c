/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:14:47 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int32_t	ft_putnbr_fd(int32_t nbr, int32_t fd)
{
	char	c;
	size_t	i;

	i = 0;
	if (nbr == -2147483648)
		return (ft_putstr_fd("-2147483648", fd), 11);
	else if (nbr < 0)
	{
		i += ft_putchar_fd('-', fd);
		nbr = ft_abs(nbr);
	}
	if (nbr >= 10)
	{
		i += ft_putnbr_fd(nbr / 10, fd);
		i += ft_putnbr_fd(nbr % 10, fd);
	}
	else if (nbr < 10 && nbr != -2147483648)
	{
		c = nbr + '0';
		i += ft_putchar_fd(c, fd);
	}
	return (i);
}
