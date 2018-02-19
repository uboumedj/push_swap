/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oldsolve_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:04:10 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/17 15:23:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int					*three_max(t_stack *a)
{
	int			*tab;
	t_stack		*temp;
	int			i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * 3)))
		mem_error();
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
			temp = temp->next;
		}
		i++;
	}
	return (tab);
}

void				solve_helper(t_stack **a, t_stack **b)
{
	int		med;

	med = med_val(*a);
	if ((*a)->content == min_val(*a))
	{
		pb(a, b);
		ft_printf("pb\n");
	}
	if ((*a)->content <= med)
	{
		if (((*a)->content > (*b)->content && (*b)->content == max_val(*b))
				|| (*a)->content < min_val(*b))
		{
			pb(a, b);
			ft_printf("pb\n");
		}
		else
		{
			if ((*a)->content < (*b)->content)
			{
				while ((*a)->content < (*b)->content)
				{
					rb(b);
					ft_printf("rb\n");
				}
				pb(a, b);
				ft_printf("pb\n");
			}
			else
			{
				while ((*a)->content < last_val(*b))
				{
					rrb(b);
					ft_printf("rrb\n");
				}
				pb(a, b);
				ft_printf("pb\n");
			}
		}
	}
	else
	{
		ra(a);
		ft_printf("ra\n");
	}
}

void				solve_big_len(t_stack **a, t_stack **b)
{
	int		len;
	int		*maxthree;

	len = ft_stacklen(*a);
	maxthree = three_max(*a);
	while (check_sort(*a) == 0 && len > 3)
	{
		if ((*a)->content == maxthree[0] || (*a)->content == maxthree[1] ||
				(*a)->content == maxthree[2])
		{
			ra(a);
			ft_printf("ra\n");
		}
		solve_helper(a, b);
	}
	if (len == 3)
		solve_three(a);
	while (*b && (*b)->content != max_val(*b))
	{
		rb(b);
		ft_printf("rb\n");
	}
	while (*b)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
	free(maxthree);
}
