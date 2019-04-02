/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:20:47 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:52:25 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** main function of the push_swap program.
*/

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;
	t_flags		*flags;
	int			cflags;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		cflags = check_for_flags(argv, &flags);
		if (argc == 2 + cflags)
			args = ft_strsplit(argv[1 + cflags], ' ');
		else
			args = ft_strarrdup(&argv[1 + cflags]);
		argc = ft_strarraylen(args);
		get_numbers(&a, argc, args);
		solve(&a, &b, &flags);
		freedom(a, b, flags, args);
	}
	else
		ft_printf("usage: ./push_swap -[options] numbers list (n1 n2...)\n");
	return (0);
}
