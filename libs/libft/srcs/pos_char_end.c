/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_char_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:33:35 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/17 17:55:53 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Finds the last occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_end(char *str, char n)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	while (str[len] != n && len > 0)
		len--;
	return (len);
}
