/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:04:10 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:23:31 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void				push_back_to_a(t_stack **a, t_stack **b)
{
	if (max_index(*b) > stack_len(*b) / 2)
	{
		while ((*b)->content != max_val(*b))
		{
			rrb(b);
			ft_putstr("rrb\n");
		}
	}
	else
	{
		while ((*b)->content != max_val(*b))
		{
			rb(b);
			ft_putstr("rb\n");
		}
	}
	while (*b)
	{
		pa(a, b);
		ft_putstr("pa\n");
	}
}

void				solve_big_len(t_stack **a, t_stack **b)
{
	int		len;
	t_data	*data;

	if (check_sort(*a) == 0)
	{
		len = stack_len(*a);
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			mem_error();
		while (*a)
		{
			min_steps(a, b, data);
		}
		if (stack_len(*a) == 3)
			solve_three(a);
		push_back_to_a(a, b);
		free(data);
	}
}
