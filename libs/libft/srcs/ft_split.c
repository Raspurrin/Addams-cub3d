/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:47:06 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static bool	allocate(char **out, const char *str, char del, \
				size_t wcount)
{
	size_t	count;
	size_t	index;

	index = 0;
	while (*str && index < wcount)
	{
		count = 0;
		while (*str == del && *str)
			str++;
		while (str[count] && str[count] != del)
			count++;
		out[index] = malloc(sizeof(char) * (count + 1));
		if (!out[index])
			return (false);
		ft_strlcpy(out[index], str, count + 1);
		str += count;
		index++;
	}
	return (true);
}

char	**ft_split(const char *str, char del)
{
	char	**out;
	size_t	wcount;

	if (!str)
		return (NULL);
	wcount = ft_wcount(str, del);
	out = malloc(sizeof(char *) * (wcount + 1));
	if (!out)
		return (NULL);
	if (!allocate(out, str, del, wcount))
	{
		while (*out)
		{
			free(*out);
			out++;
		}
		return (NULL);
	}
	out[wcount] = NULL;
	return (out);
}
