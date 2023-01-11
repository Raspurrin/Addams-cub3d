/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_char_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 05:32:38 by mialbert          #+#    #+#             */
/*   Updated: 2022/11/17 17:57:22 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * Finds the first occurance of char in the string 
 * and returns that position.
 */
size_t	pos_char_start(char *str, char n)
{
	size_t	len;

	len = 0;
	while (str[len] != n && str[len])
		len++;
	return (len);
}
