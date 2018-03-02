/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:02:55 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:15:46 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void			min_to_top(t_stack **a, t_stack **b, t_flags **flags)
{
	int index;

	index = min_index(*a);
	if (index <= (stack_len(*a) / 2))
	{
		ra(a, b, flags);
		ft_putstr("ra\n");
	}
	else if (index > (stack_len(*a) / 2))
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}

void				solve_small_len(t_stack **a, t_stack **b, t_flags **flags)
{
	int min;

	while (check_sort(*a) == 0 || *b)
	{
		if (stack_len(*a) == 3)
			solve_three(a, b, flags);
		min = min_val(*a);
		while ((*a)->content != min)
			min_to_top(a, b, flags);
		if (check_sort(*a) == 0)
		{
			pb(a, b, flags);
			ft_putstr("pb\n");
		}
		else
		{
			while (*b)
			{
				pa(a, b, flags);
				ft_putstr("pa\n");
			}
		}
	}
	do_count(*flags);
}
