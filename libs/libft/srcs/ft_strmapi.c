/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:19:40 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *str, char (*f)(uint32_t, char))
{
	size_t	i;
	char	*out;

	i = 0;
	if (!str)
		return (NULL);
	out = malloc(ft_strlen((char *)str) + 1 * sizeof(char));
	if (!out)
		return (NULL);
	while (str[i])
	{
		out[i] = f(i, str[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
