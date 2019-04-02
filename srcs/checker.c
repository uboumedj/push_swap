/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:33:46 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 18:05:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** main function of the checker program
*/

int				main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		*line;
	char		**args;
	t_flags		*flags;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		line = NULL;
		if (argc == 2 + check_for_flags(argv, &flags))
			args = ft_strsplit(argv[1 + check_for_flags(argv, &flags)], ' ');
		else
			args = ft_strarrdup(&argv[1 + check_for_flags(argv, &flags)]);
		get_numbers(&a, ft_strarraylen(args), args);
		do_operations(line, &a, &b, &flags);
		ft_printf(((check_sort(a) && !b) ? "OK\n" : "KO\n"));
		freedom(a, b, flags, args);
	}
	else
		ft_printf("usage: ./checker -[options] numbers list (n1 n2...)\n");
	return (0);
}
