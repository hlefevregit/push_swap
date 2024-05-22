/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:56:04 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:14:20 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list *lst)
{
	t_list	*d;
	t_list	*t;

	t = lst;
	while (t)
	{
		d = t->next;
		free(d);
		t = d;
	}
	free(lst);
}
