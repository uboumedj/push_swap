/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:51 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/15 21:21:05 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		revrotate(t_stack *stack)
{
	t_stack		*inc;
	int				prev_c;
	int				cur_c;

	if (stack && stack->next)
	{
		inc = stack;
		prev_c = inc->content;
		while (inc->next)
		{
			cur_c = inc->next->content;
			inc->next->content = prev_c;
			prev_c = cur_c;
			inc = inc->next;
		}
		stack->content = prev_c;
	}
}

void					rra(t_stack *a)
{
	revrotate(a);
}

void					rrb(t_stack *b)
{
	revrotate(b);
}

void					rrr(t_stack *a, t_stack *b)
{
	revrotate(a);
	revrotate(b);
}
