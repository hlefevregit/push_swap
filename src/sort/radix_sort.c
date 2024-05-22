/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:44:31 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:43:47 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_bits(t_list *stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack stack)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = stack.a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack.a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = stack.a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack);
			else
				pb(stack);
		}
		while (ft_lstsize(stack.b) != 0)
			pa(stack);
		i++;
	}
}