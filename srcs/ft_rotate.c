/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:53:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 16:17:38 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		rotate(t_pile *pile)
{
	t_pile	*temp;
	int		first;

	if (pile)
	{
		temp = pile;
		first = pile->content;
		while (temp->next)
		{
			temp->content = temp->next->content;
			temp = temp->next;
		}
		temp->content = first;
	}
}

void			ra(t_pile *a)
{
	rotate(a);
}

void			rb(t_pile *b)
{
	rotate(b);
}

void			rr(t_pile *a, t_pile *b)
{
	rotate(a);
	rotate(b);
}
