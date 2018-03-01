/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:53:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 19:42:51 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		rotate(t_stack **stack)
{
	t_stack		*temp;
	int			first;

	if (*stack)
	{
		temp = *stack;
		first = (*stack)->content;
		while (temp->next)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
	}
}

void			ra(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rb(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			rr(t_stack **a, t_stack **b, t_flags **flags)
{
	rotate(a);
	rotate(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
