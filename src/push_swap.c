/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:01:23 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:43:30 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_init_stack(t_list *a, int ac, char **av)
{
	char	**args;
	int		i;

	i = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(args[i])));
		printf("lst[%i] = %i\n", i, ft_lstlast(a)->content);
		i++;
	}
	index_stack(a);
	if (ac == 2)
		ft_free(args);
}

static void	sort_stack(t_stack stack)
{
	if (ft_lstsize(stack.a) <= 5)
		sort_3_to_5(stack);
	else
		radix_sort(stack);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac < 2)
		return (ft_strerror());
	if (ft_check_args(ac, av) == -1)
		return (ft_strerror());
	// stack.a = (t_list *)malloc(sizeof(t_list));
	// stack.b = (t_list *)malloc(sizeof(t_list));
	stack.a = NULL;
	stack.b = NULL;
	ft_init_stack(stack.a, ac, av);
	if (is_sorted(stack.a) == 1)
	{
		printf("ALREDAY SORTED\n");
		free_stack(stack.a);
		return (0);
	}
	sort_stack(stack);
	free_stack(stack.a);
	free_stack(stack.b);
	return (0);
}