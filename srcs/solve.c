/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:18:09 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/01 15:51:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	solve(t_stack **a, t_stack **b)
{
	int		len;

	if (!(len = ft_stacklen(*a)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (check_sort(*a) == 0)
	{
		if (len <= 3)
			solve_three(a);
		else if (len < 8)
			solve_small_len(a, b);
		else
			solve_big_len(a, b);
	}
}
