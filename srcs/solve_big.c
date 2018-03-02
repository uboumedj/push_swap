/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:04:10 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:13:48 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void				order_b(t_stack **a, t_stack **b, t_flags **flags)
{
	if (max_index(*b) > stack_len(*b) / 2)
	{
		while ((*b)->content != max_val(*b))
		{
			rrb(a, b, flags);
			ft_putstr("rrb\n");
		}
	}
	else
	{
		while ((*b)->content != max_val(*b))
		{
			rb(a, b, flags);
			ft_putstr("rb\n");
		}
	}
}

void				push_back_to_a(t_stack **a, t_stack **b, t_flags **flags)
{
	while (*b && (*b)->content > last_val(*a))
	{
		pa(a, b, flags);
		ft_putstr("pa\n");
	}
	if (*b)
	{
		if (stack_len(*a) != 1)
		{
			rra(a, b, flags);
			ft_putstr("rra\n");
		}
		while (*b)
		{
			pa(a, b, flags);
			ft_putstr("pa\n");
		}
	}
	if ((*a)->content > last_val(*a))
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}

void				solve_big_len(t_stack **a, t_stack **b, t_flags **flags)
{
	int		len;
	t_data	*data;

	if (check_sort(*a) == 0)
	{
		len = stack_len(*a);
		if (!(data = (t_data *)malloc(sizeof(t_data))))
			cmn_error();
		while (stack_len(*a) != 1)
			min_steps(a, b, data, flags);
		order_b(a, b, flags);
		push_back_to_a(a, b, flags);
		free(data);
		do_count(*flags);
	}
}
