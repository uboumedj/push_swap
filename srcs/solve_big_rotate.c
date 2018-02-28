/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:26:53 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:02:55 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	rotations(t_stack **a, t_stack **b, t_data *data)
{
	data->ra = 0;
	data->rb = 0;
	data->rra = 0;
	data->rrb = 0;
	if (data->min_index <= stack_len(*a) / 2)
		data->ra = data->min_index;
	else
		data->rra = stack_len(*a) - data->min_index;
	if (data->place <= stack_len(*b) / 2)
		data->rb = (data->min_steps - data->rra - data->ra - 1);
	else
		data->rrb = (data->min_steps - data->rra - data->ra - 1);
	rot(a, b, data);
	revrot(a, b, data);
	pb(a, b);
	ft_putstr("pb\n");
}

void	rot(t_stack **a, t_stack **b, t_data *data)
{
	while (data->ra > 0 && data->rb > 0)
	{
		rr(a, b);
		ft_putstr("rr\n");
		(data->ra)--;
		(data->rb)--;
	}
	while (data->ra > 0)
	{
		ra(a);
		ft_putstr("ra\n");
		(data->ra)--;
	}
	while (data->rb > 0)
	{
		rb(b);
		ft_putstr("rb\n");
		(data->rb)--;
	}
}

void	revrot(t_stack **a, t_stack **b, t_data *data)
{
	while (data->rra > 0 && data->rrb > 0)
	{
		rrr(a, b);
		ft_putstr("rrr\n");
		(data->rra)--;
		(data->rrb)--;
	}
	while (data->rra > 0)
	{
		rra(a);
		ft_putstr("rra\n");
		(data->rra)--;
	}
	while (data->rrb > 0)
	{
		rrb(b);
		ft_putstr("rrb\n");
		(data->rrb)--;
	}
}
