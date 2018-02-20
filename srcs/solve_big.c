/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 16:04:10 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/20 02:00:36 by uboumedj         ###   ########.fr       */
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

void				push_back_to_a(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
		ft_printf("pa\n");
	}
}

void				solve_helper(t_stack **a, t_stack **b)
{
	int minstep_idx;

	minstep_idx = min_steps(a, b);
}

void				solve_big_len(t_stack **a, t_stack **b)
{
	int		len;
	int		*maxthree;

	len = ft_stacklen(*a);
	maxthree = three_max(*a);
	while (check_sort(*a) == 0 && stack_len(*a) > 3)
	{
		if ((*a)->content == maxthree[0] || (*a)->content == maxthree[1] ||
				(*a)->content == maxthree[2])
		{
			ra(a);
			ft_printf("ra\n");
		}
		else
			solve_helper(a, b);
	}
	if (len == 3)
		solve_three(a);
	push_back_to_a(a, b);
	free(maxthree);
}
