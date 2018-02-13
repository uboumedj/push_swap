/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:20:47 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/13 15:17:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	char		**args;

	if (argc > 1)
	{
		a = ft_stacknew(0);
		b = NULL;
		if (argc == 2)
			args = ft_strsplit(argv[1], ' ');
		else
			args = &argv[1];
		argc = ft_strarraylen(args);
		get_numbers(&a, argc, args);
		solve(&a, &b);
		ft_stackfree(&a);
		ft_stackfree(&b);
		//ft_strarrayfree(args);
	}
	else
		ft_printf("usage: ./checker -[options] numbers list (n1 n2...)\n");
	return (0);
}
