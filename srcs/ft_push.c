/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:00:16 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:11:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** Push instructions coding. Pushing takes the first element from the stack and
** pushes it to the other: [pa] pushes from stack b to stack a, and
** [pb] pushes from stack a to stack b.
*/

static void		push(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (*a)
	{
		temp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = temp;
	}
}

void			pa(t_stack **a, t_stack **b, t_flags **flags)
{
	push(b, a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			pb(t_stack **a, t_stack **b, t_flags **flags)
{
	push(a, b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
