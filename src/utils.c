/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:26:28 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 18:28:21 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list *stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = stack;
	if (head)
	{
		while (head)
		{
			if ((head->index < 0) && (!has_min || head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list *stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

int	is_sorted(t_list *stack)
{
	t_list	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_list *stack)
{
	t_list	*head;
	t_list	*tmp;

	head = stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	// free(stack);
}
