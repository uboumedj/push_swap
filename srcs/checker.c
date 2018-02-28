/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:33:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:18:08 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	char		**args;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		line = NULL;
		if (argc == 2)
			args = ft_strsplit(argv[1], ' ');
		else
			args = &argv[1];
		get_numbers(&a, ft_strarraylen(args), args);
		do_operations(line, &a, &b);
		ft_printf((check_sort(a) ? "OK\n" : "KO\n"));
		ft_stackfree(&a);
		ft_stackfree(&b);
	}
	else
		ft_printf("usage: ./checker -[options] numbers list (n1 n2...)\n");
	return (0);
}
