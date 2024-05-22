/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:47:25 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:16 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_stack stack)
{
	if (reverse_rotate(stack.a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack stack)
{
	if (reverse_rotate(stack.b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack stack)
{
	if ((ft_lstsize(stack.a) < 2) || (ft_lstsize(stack.b) < 2))
		return (-1);
	reverse_rotate(stack.a);
	reverse_rotate(stack.b);
	ft_putendl_fd("rrr", 1);
	return (0);
}

int	reverse_rotate(t_list *stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = stack;
	stack = tail;
	return (0);
}
