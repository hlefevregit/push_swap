/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:49:56 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:40:04 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack stack)
{
	if (swap(stack.a) == -1)	
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_stack stack)
{
	if (swap(stack.b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_stack stack)
{	
	if ((ft_lstsize(stack.a) < 2) || (ft_lstsize(stack.b) < 2))
		return (-1);
	swap(stack.a);
	swap(stack.b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	swap(t_list *stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = stack;
	next = head->next;
	if (!head && !next)
		ft_strerror();
	tmp_val = head->content;
	tmp_index = head->index;
	head->content = next->content;
	head->index = next->index;
	next->content = tmp_val;
	next->index = tmp_index;
	return (0);
}