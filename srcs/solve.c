/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:18:09 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/25 17:42:16 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void	min_to_top(t_stack **a)
{
	int index;

	index = min_index(*a);
	if (index == 2)
	{
		sa(a);
		ft_printf("sa\n");
	}
	else if (index < (ft_stacklen(*a) / 2))
	{
		ra(a);
		ft_printf("ra\n");
	}
	else if (index >= (ft_stacklen(*a) / 2))
	{
		rra(a);
		ft_printf("rra\n");
	}
}

void				solve_small_len(t_stack **a, t_stack **b)
{
	int min;

	while (check_sort(*a) == 0)
	{
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

void				solve_big_len(t_stack **a, t_stack **b)
{
	ft_printf("big\n");
}

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
