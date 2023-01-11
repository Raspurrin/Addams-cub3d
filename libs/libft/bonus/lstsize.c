/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:38:43 by mialbert          #+#    #+#             */
/*   Updated: 2022/07/26 18:41:45 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	lstsize(void *lst)
{
	t_list	*lst2;
	size_t	i;

	i = 0;
	lst2 = (t_list *)lst;
	if (!lst2)
		return (0);
	while (lst2 != NULL)
	{
		lst2 = lst2->next;
		i++;
	}
	return (i);
}
