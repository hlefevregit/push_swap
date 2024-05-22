/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:44:29 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:35 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack stack)
{
	if (rotate(stack.a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_stack stack)
{
	if (rotate(stack.b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}

int	rr(t_stack stack)
{
	if ((ft_lstsize(stack.a) < 2) || (ft_lstsize(stack.b) < 2))
		return (-1);
	rotate(stack.a);
	rotate(stack.b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	rotate(t_list *stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack;
	tail = ft_lstlast(head);
	stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}
