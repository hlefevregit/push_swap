/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:59:01 by hulefevr          #+#    #+#             */
/*   Updated: 2024/05/23 16:00:40 by hulefevr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSUH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_stack
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*args;
}				t_stack;

int		ft_check_args(int ac, char **av);
int		ft_atol(const char *n, t_stack *s);
int		is_array_sorted(t_stack *s);

void	free_and_exit_with_message(t_stack *s, char *msg);
void	validate_arguments(int argc, char **argv);
void	parse_numbers(t_stack *s);
void	exit_if_sorted_or_has_duplicate(t_stack *s, int i);
void	create_index(t_stack *s);
void	radix_sort(t_stack *s);
void	sort_four_to_five_elements(t_stack *s);
void	sort_three_elements(t_stack *s);

/************LIBFT****************/

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_count_words(char const *s, char c);

char	**ft_split(char const *s, char c);

char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);

/**********OPERATORS***************/

void	swap(char *str, int *array, int size);
void	push(char *str, t_stack *s);
void	rotate(int *array, int size, char *direction, char *list);

#endif