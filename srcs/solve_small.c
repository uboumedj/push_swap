/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_small.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:02:55 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:24:05 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void			min_to_top(t_stack **a)
{
	int index;

	if ((*a)->content > (*a)->next->content)
	{
		sa(a);
		ft_printf("sa\n");
	}
	index = min_index(*a);
	if (index < (stack_len(*a) / 2) && index != 1)
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if (index >= (stack_len(*a) / 2) && index != 1)
	{
		rra(a);
		ft_printf("rra\n");
	}
}

void				solve_small_len(t_stack **a, t_stack **b)
{
	int min;

	while (check_sort(*a) == 0 || *b)
	{
		if (stack_len(*a) == 3)
			solve_three(a);
		min = min_val(*a);
		while ((*a)->content != min)
			min_to_top(a);
		if (check_sort(*a) == 0)
		{
			pb(a, b);
			ft_printf("pb\n");
		}
		else
		{
			while (*b)
			{
				pa(a, b);
				ft_printf("pa\n");
			}
		}
	}
}
