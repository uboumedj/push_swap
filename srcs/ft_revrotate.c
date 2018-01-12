/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 16:17:51 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 16:29:37 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	revrotate(t_pile *pile)
{
	t_list	*last;
	int		temp;

	if (pile && pile->next)
	{
		last = pile;
		temp = last->content;
		while (last->next)
		{
			temp = last->next->content;
			last->next->content = last->content;
			last = last->next;
		}
	}
}
