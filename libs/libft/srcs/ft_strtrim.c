/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:20:07 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/15 19:53:27 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *str, char const *set)
{
	size_t	end;

	if (!str)
		return (NULL);
	while (ft_strchr(set, *str) && *str)
		str++;
	if (!*str)
		return (ft_strdup(""));
	end = ft_strlen(str);
	while (ft_strrchr(set, str[end]) && end > 0)
		end--;
	return (ft_substr(str, 0, end + 1));
}
