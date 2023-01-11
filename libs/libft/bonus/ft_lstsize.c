/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mialbert <mialbert@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 21:13:43 by mialbert          #+#    #+#             */
/*   Updated: 2021/12/02 23:50:37 by mialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*counter;
	size_t	i;

	counter = lst;
	i = 0;
	if (!lst)
		return (0);
	while (counter != NULL)
	{
		counter = counter->next;
		i++;
	}
	return (i);
}
