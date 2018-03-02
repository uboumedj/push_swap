/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 03:03:18 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:15:21 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		three_min_sec(t_stack **a, t_stack **b, t_flags **flags)
{
	if ((*a)->content > (*a)->next->next->content)
	{
		ra(a, b, flags);
		ft_putstr("ra\n");
	}
	else
	{
		sa(a, b, flags);
		ft_putstr("sa\n");
	}
}

static void		three_min_third(t_stack **a, t_stack **b, t_flags **flags)
{
	if ((*a)->content > (*a)->next->content)
	{
		sa(a, b, flags);
		ft_putstr("sa\n");
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
	else
	{
		rra(a, b, flags);
		ft_putstr("rra\n");
	}
}

void			solve_three(t_stack **a, t_stack **b, t_flags **flags)
{
	t_stack		*temp;
	int			min;

	if (check_sort(*a) == 0)
	{
		temp = *a;
		min = min_val(*a);
		if (stack_len(*a) == 2)
		{
			sa(a, b, flags);
			ft_putstr("sa\n");
		}
		else if (temp->content == min)
		{
			rra(a, b, flags);
			ft_putstr("rra\n");
			sa(a, b, flags);
			ft_putstr("sa\n");
		}
		else if (temp->next->content == min)
			three_min_sec(a, b, flags);
		else if (temp->next->next->content == min)
			three_min_third(a, b, flags);
	}
}
