/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:00:16 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 16:16:43 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		push(t_pile **a, t_pile **b)
{
	t_pile *temp;

	if (*a)
	{
		temp = (*a)->next;
		(*a)->next = (*b);
		(*b) = (*a);
		(*a) = temp;
	}
}

void			pa(t_pile *a, t_pile *b)
{
	push(&a, &b);
}

void			pb(t_pile *a, t_pile *b)
{
	push(&b, &a);
}
