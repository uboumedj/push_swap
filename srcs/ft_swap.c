/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:35:36 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 19:36:56 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** Swap instructions coding. Performing a swap on a stack means swapping the
** first two elements of the stack. [sa] swaps the first two elements of
** stack a, [sb] swaps the first two elements of stack b, and
** [ss] performs |sa| and |sb| at the same time.
*/

static void		swap(t_stack **stack)
{
	int temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = temp;
	}
}

void			sa(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			sb(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}

void			ss(t_stack **a, t_stack **b, t_flags **flags)
{
	swap(a);
	swap(b);
	if ((*flags)->v)
		display_stacks(*a, *b);
	if ((*flags)->count)
		((*flags)->nb)++;
}
