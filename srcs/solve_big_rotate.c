/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:26:53 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/20 01:57:49 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	rotations(t_stack **a, t_stack **b, t_data *data)
{
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
	ft_printf("pb\n");
}

void	rot(t_stack **a, t_stack **b, t_data *data)
{
	while (data->ra && data->rb)
	{
		rr(a, b);
		ft_printf("rr\n");
		(data->ra)--;
		(data->rb)--;
	}
	while (data->ra)
	{
		ra(a);
		ft_printf("ra\n");
		(data->ra)--;
	}
	while (data->rb)
	{
		rb(b);
		ft_printf("rb\n");
		(data->rb)--;
	}
}

void	revrot(t_stack **a, t_stack **b, t_data *data)
{
	while (data->rra && data->rrb)
	{
		rrr(a, b);
		ft_printf("rrr\n");
		(data->rra)--;
		(data->rrb)--;
	}
	while (data->rra)
	{
		rra(a);
		ft_printf("rra\n");
		(data->rra)--;
	}
	while (data->rrb)
	{
		rrb(b);
		ft_printf("rrb\n");
		(data->rrb)--;
	}
}
