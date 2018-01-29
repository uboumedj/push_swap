/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:04:10 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/28 12:41:48 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int 				*three_max(t_stack *a)
{
	int 		tab[3];
	t_stack	*temp;
	int 		i;

	i = 0;
	while (i < 3)
	{
		temp = a;
		tab[i] = temp->content;
		while (temp)
		{
			if (i == 0)
				tab[i] = (temp->content > tab[i]) ? temp->content : tab[i];
			else if (i == 1)
				tab[i] = (temp->content > tab[i]
										&& temp->content != tab[0]) ? temp->content : tab[i];
			else if (i == 2)
				tab[i] = (temp->content > tab[i] && (temp->content != tab[0]
										&& temp->content != tab[1])) ? temp->content : tab[i];
			temp = temp->next
		}
		i++;
	}
	return (tab);
}

void				solve_big_len(t_stack **a, t_stack **b)
{
	int 	len;
	int 	maxthree[3];

	len = ft_stacklen(*a);
	maxthree = three_max(*a);
	while (check_sort(*a) == 0 && len > 3)
	{

	}
	if (len == 3)
	{
		solve_three(a);
		while (*b)
		{
			pa(a, b);
			ft_printf("pa\n");
		}
	}
}
