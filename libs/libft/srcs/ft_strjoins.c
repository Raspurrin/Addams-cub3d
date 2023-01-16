/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:28:46 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/27 15:44:11 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdarg.h>

char	*ft_strjoins(char *join(), ...)
{
	char	*out;
	char	*str;
	va_list	argp;

	va_start(argp, join);
	str = va_arg(argp, char *);
	out = ft_strdup("");
	while (str)
	{
		out = join(out, str);
		str = va_arg(argp, char *);
	}
	return (out);
}
