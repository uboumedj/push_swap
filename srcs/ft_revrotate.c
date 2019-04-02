/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:51 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 19:36:30 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** Reverse rotate instructions coding. Reverse-rotating means, if you look at
** the stack from left to right, left-most element being the one at the top of
** the stack, you're rotating one notch right, and the last element becomes the
** first. [rra] reverse rotates the stack a, [rrb] reverse rotates the stack b,
** and [rrr] reverse rotates both at the same time.
*/

static void		revrotate(t_stack **stack)
{
	t_stack		*inc;
	int			prev_c;
	int			cur_c;

	if (*stack && (*stack)->next)
	{
		inc = *stack;
		prev_c = inc->content;
		while (inc->next)
		{
			cur_c = inc->next->content;
			inc->next->content = prev_c;
			prev_c = cur_c;
			inc = inc->next;
		}
		(*stack)->content = prev_c;
	}
}

void			rra(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rrb(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rrr(t_stack **a, t_stack **b, t_flags **flags)
{
	revrotate(a);
	revrotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
