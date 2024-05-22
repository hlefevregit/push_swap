/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:00:56 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:42 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_stack stack)
{
	if (push(stack.a, stack.b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_stack stack)
{
	if (push(stack.b, stack.a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	push(t_list *stack_to, t_list *stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(stack_from) == 0)
		return (-1);
	head_to = stack_to;
	head_from = stack_from;
	tmp = head_from;
	head_from = head_from->next;
	stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		stack_to = tmp;
	}
	return (0);
}
