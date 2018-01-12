/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:51 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 21:40:22 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		revrotate(t_pile *pile)
{
	t_list	*inc;
	int		prev_c;
	int		cur_c;

	if (pile && pile->next)
	{
		inc = pile;
		prev_c = inc->content;
		while (inc->next)
		{
			cur_c = inc->next->content;
			inc->next->content = prev_c;
			prev_c = cur_c;
			inc = inc->next;
		}
		pile->content = prev_c;
	}
}

void					rra(t_pile *a)
{
	revrotate(a);
}

void					rrb(t_pile *b)
{
	revrotate(b);
}

void					rrr(t_pile *a, t_pile *b)
{
	revrotate(a);
	revrotate(b);
}
