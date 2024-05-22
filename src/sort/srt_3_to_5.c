/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srt_3_to_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:44:51 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:37:52 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3_stack(t_stack stacks)
{
	int		first;
	int		second;
	int		third;

	first = stacks.a->content;
	second = stacks.a->next->content;
	third = stacks.a->next->next->content;
	if (first > second && second < third && first < third)
		sa(stacks);
	else if (first > second && second > third)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (first < second && second > third && first < third)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (first > second && second < third && first > third)
		ra(stacks);
	else if (first < second && second > third && first > third)
		rra(stacks);
}

static void	sort_4_or_5_stack(t_stack stacks, int median)
{
	int		pb_count;
	t_list	*a;
	t_list	*b;

	a = stacks.a;
	b = stacks.b;
	pb_count = 0;
	while (pb_count < median)
	{
		if (a->content < median)
		{
			pb(stacks);
			pb_count++;
		}
		else
			ra(stacks);
	}
	sort_3_stack(stacks);
	if (median > 1)
	{
		if ((b->content) < (ft_lstlast(stacks.b)->content))
			sb(stacks);
		pa(stacks);
	}
	pa(stacks);
}

void	sort_3_to_5(t_stack stack)
{
	int		first;
	int		last;

	first = stack.a->content;
	last = ft_lstlast(stack.a)->content;
	if (stack.a->index == 2 && first > last)
		ra(stack);
	else if (ft_lstsize(stack.a) == 3)
		sort_3_stack(stack);
	else if (ft_lstsize(stack.a) == 4)
		sort_4_or_5_stack(stack, 1);
	else if (ft_lstsize(stack.a) == 5)
		sort_4_or_5_stack(stack, 2);
}