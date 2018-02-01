/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 03:03:18 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/01 15:57:03 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		three_min_sec(t_stack **a)
{
	if ((*a)->content > (*a)->next->next->content)
	{
		ra(a);
		ft_printf("ra\n");
	}
	else
	{
		sa(a);
		ft_printf("sa\n");
	}
}

static void		three_min_third(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		sa(a);
		rra(a);
		ft_printf("sa\nrra\n");
	}
	else
	{
		rra(a);
		ft_printf("rra\n");
	}
}

void			solve_three(t_stack **a)
{
	t_stack		*temp;
	int			min;

	temp = *a;
	min = min_val(*a);
	if (ft_stacklen(*a) == 2)
	{
		sa(a);
		ft_printf("sa\n");
	}
	else if (temp->content == min)
	{
		rra(a);
		sa(a);
		ft_printf("rra\nsa\n");
	}
	else if (temp->next->content == min)
		three_min_sec(a);
	else if (temp->next->next->content == min)
		three_min_third(a);
}
