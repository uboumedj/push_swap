/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:20:47 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 15:21:01 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	t_flags		*flags;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		if (argc == 2 + check_for_flags(argv[1], &flags))
			args = ft_strsplit(argv[1 + check_for_flags(argv[1], &flags)], ' ');
		else
			args = ft_strarrdup(&argv[1 + check_for_flags(argv[1], &flags)]);
		argc = ft_strarraylen(args);
		get_numbers(&a, argc, args);
		solve(&a, &b, &flags);
		freedom(a, b, flags, args);
	}
	else
		ft_printf("usage: ./push_swap -[options] numbers list (n1 n2...)\n");
	return (0);
}
