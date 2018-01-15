/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:53:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/15 21:22:45 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		rotate(t_stack *stack)
{
	t_stack		*temp;
	int				first;

	if (stack)
	{
		temp = stack;
		first = stack->content;
		while (temp->next)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
	}
}

void			ra(t_stack *a)
{
	rotate(a);
}

void			rb(t_stack *b)
{
	rotate(b);
}

void			rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}
