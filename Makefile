# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 16:31:48 by uboumedj          #+#    #+#              #
#    Updated: 2018/02/01 14:53:03 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

CH_SRCS = srcs/check_ops.c srcs/check_tests.c srcs/checker.c srcs/get_numbers.c \
		  srcs/ft_push.c srcs/ft_revrotate.c srcs/ft_rotate.c srcs/ft_swap.c

PS_SRCS = srcs/push_swap.c srcs/solve.c srcs/get_numbers.c srcs/check_tests.c \
		  srcs/ft_push.c srcs/ft_revrotate.c srcs/ft_rotate.c srcs/ft_swap.c \
		  srcs/solve_big.c srcs/solve_small.c srcs/solve_three.c \
		  srcs/basic_functions.c

INC = ft_push_swap.h

CH_OBJS = $(CH_SRCS:.c=.o)
PS_OBJS = $(PS_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH):
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME_CH) -Iinclude $(LIBFT)/libft.a $(CH_SRCS)
	@echo "\033[1;34mchecker\033[1;32m...compiled\t✓\033[0m"

$(NAME_PS):
	@make -C $(LIBFT)
	@ $(CC) $(FLAGS) -o $(NAME_PS) -Iinclude $(LIBFT)/libft.a $(PS_SRCS)
	@echo "\033[1;34mpush_swap\033[1;32m..compiled\t✓\033[0m"

clean:
	@rm -rf $(CH_OBJS) $(PS_OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME_PS) $(NAME_CH)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m files deleted\t\t\033[1;31m✓\033[0m"

re: fclean all
