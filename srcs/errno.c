/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errno.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:15:25 by mialbert          #+#    #+#             */
/*   Updated: 2023/02/16 01:15:26 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/** 
 * @brief Writes an error message to STDERR.
 * You can add an additional message, otherwise add "" as 2nd argument.
 * @param nbr Signifies with error message from the array to be used.
 * @param msg additional message after the error message.
 */
void	errno(int8_t nbr, char *msg, t_data *data)
{
	static const char	*errors[] = {
		"Too many arguments",
		"Failed reading the file",
		"Wrong colour channel given in input file. Ex: C 220,100,0",
		"You need to give a .cub file as argument",
		"Contains invalid characters",
		"Wrong file extension",
		"The map must be closed/surrounded by walls",
		"Invalid texture: ",
		"Too many players",
		"Map doesn't contain a player"
	};

	ft_printf_fd(STDERR_FILENO, "Error\n%s%s\n", errors[nbr], msg);
	free_data(data);
	exit(nbr);
}

// testest
