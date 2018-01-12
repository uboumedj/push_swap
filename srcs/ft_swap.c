/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 15:35:36 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 16:17:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

static void		swap(t_pile *pile)
{
	int temp;

	if (pile && pile->next)
	{
		temp = pile->content;
		pile->content = pile->next->content;
		pile->next->content = temp;
	}
}

void			sa(t_pile *a)
{
	swap(a);
}

void			sb(t_pile *b)
{
	swap(b);
}

void			ss(t_pile *a, t_pile *b)
{
	swap(a);
	swap(b);
}
