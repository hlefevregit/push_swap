# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 12:55:59 by hulefevr          #+#    #+#              #
#    Updated: 2024/05/22 17:00:40 by hulefevr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	./src/push_swap.c \
		./src/utils.c \
		./src/ft_strerror.c \
		./src/ft_check_args.c \
		./src/sort/radix_sort.c  \
		./src/sort/srt_3_to_5.c \
		./src/op/op_p.c \
		./src/op/op_r.c \
		./src/op/op_rr.c \
		./src/op/op_s.c \
		./src/lib/ft_atoi.c \
		./src/lib/ft_isdigit.c \
		./src/lib/ft_lstadd_back.c \
		./src/lib/ft_lstadd_front.c \
		./src/lib/ft_lstclear.c \
		./src/lib/ft_lstnew.c \
		./src/lib/ft_lstsize.c \
		./src/lib/ft_split.c \
		./src/lib/ft_strlen.c \
		./src/lib/ft_putstr_fd.c \
		./src/lib/ft_putendl_fd.c \
		./src/lib/ft_lstlast.c \
		./src/lib/ft_strlcpy.c \
		./src/lib/ft_putchar_fd.c \

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

CC = gcc

LIBFT_DIR = libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

LIBFT_FLAGS = -L$(LIBFT_DIR)

RM = rm -f

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re