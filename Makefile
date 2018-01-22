# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/22 16:31:48 by uboumedj          #+#    #+#              #
#    Updated: 2018/01/22 16:44:37 by uboumedj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PS = push_swap
NAME_CH = checker

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

CH_SRCS =	srcs/check_ops.c srcs/check_tests.c srcs/checker.c \
					srcs/get_numbers.c \
					srcs/ft_push.c srcs/ft_revrotate.c srcs/ft_rotate.c srcs/ft_swap.c

PS_SRCS = srcs/push_swap.c srcs/solve.c \
					srcs/ft_push.c srcs/ft_revrotate.c srcs/ft_rotate.c srcs/ft_swap.c

INC = ft_push_swap.h

CH_OBJS = $(CH_SRCS:.c=.o)
PS_OBJS = $(PS_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME_PS) $(NAME_CH)

$(NAME_CH): $(CH_OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@echo "\033[1;34mchecker\033[1;32m...compiled\t✓\033[0m"

$(NAME_PS): $(PS_OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@echo "\033[1;34mpush_swap\033[1;32m..compiled\t✓\033[0m"

%.o: %.c
	@$(CC) $(FLAGS) -Iinclude -o $@ -c $<

clean:
	@rm -rf $(CH_OBJS) $(PS_OBJS)
	@make clean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m obj files removed\t\033[1;31m✓\033[0m"

fclean: clean
	@rm -rf $(NAME_PS) $(NAME_CH)
	@make fclean -C $(LIBFT)
	@echo "\033[1;34mpush_swap project\033[1;33m files deleted\t\033[1;31m✓\033[0m"

re: fclean all
	@make re -C $(LIBFT)
