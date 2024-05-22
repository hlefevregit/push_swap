/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:59:01 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/22 17:38:04 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSUH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	t_list	*a;
	t_list	*b;
}				t_stack;

int		ft_strerror(void);
int		ft_check_args(int ac, char **av);
int		is_sorted(t_list *stack);

void	index_stack(t_list *stack);
void	ft_free(char **arg);
void	free_stack(t_list *stack);
void	sort_3_to_5(t_stack stack);
void	radix_sort(t_stack stack);

/************LIBFT****************/

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *head);

void	ft_lstadd_back(t_list **stack, t_list *new);
void	ft_lstadd_front(t_list **stack, t_list *new);
void	ft_lstclear(t_list *lst);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

t_list	*ft_lstnew(int value);
t_list	*ft_lstlast(t_list *head);

char	**ft_split(char const *s, char c);

/**********OPERATORS***************/

int		pb(t_stack stack);
int		pa(t_stack stack);

int		ra(t_stack stack);
int		rb(t_stack stack);
int		rr(t_stack stack);

int		rra(t_stack stack);
int		rrb(t_stack stack);
int		rrr(t_stack stack);

int		sa(t_stack stack);
int		sb(t_stack stack);
int		ss(t_stack stack);

int		push(t_list *stack_to, t_list *stack_from);
int		swap(t_list *stack);
int		reverse_rotate(t_list *stack);
int		rotate(t_list *stack);

#endif