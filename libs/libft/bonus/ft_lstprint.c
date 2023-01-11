/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 12:36:41 by mialbert          #+#    #+#             */
/*   Updated: 2022/10/25 16:51:45 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstprint_fd(void *head, char type, int32_t fd)
{
	if (!head || !type || !fd)
		return ;
	while (head != NULL)
	{
		if (type == 'd')
			ft_printf_fd(fd, "%d", ((t_list *)head)->content);
		else if (type == 's')
			ft_printf_fd(fd, "%s", ((t_list *)head)->content);
		head = ((t_list *)head)->next;
	}
	ft_printf_fd(fd, "\n");
}

// t_list void* content
// t_nbr_node {int value, int index}
// new_nbr_node() {
// 	new_node = malloc(t_nbr_node);
// 	new_node->value = value;
// 	index = index;
// 	return new_node;
// }
// ft_lstnew(new_nbr_node(value, index));
// ((t_nbr_node *)stack_a->content)->value
// lst_clear()

/**
 * 
 * 
 */