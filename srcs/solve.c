/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:18:09 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 19:48:13 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	solve(t_stack **a, t_stack **b, t_flags **flags)
{
	int		len;

	if (!(len = stack_len(*a)))
		cmn_error();
	if (check_sort(*a) == 0)
	{
		if (len <= 3)
			solve_three(a, b, flags);
		else if (len < 8)
			solve_small_len(a, b, flags);
		else
			solve_big_len(a, b, flags);
	}
}
