/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:35:10 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/17 21:36:29 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	display_error(char *error_msg, bool yeet)
{
	perror(error_msg);
	if (yeet == true)
		exit(EXIT_FAILURE);
}
