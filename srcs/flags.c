/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:45:22 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 20:20:43 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int		check_for_flags(char *str, t_flags **flags)
{
	if (!(*flags))
	{
		if (!((*flags) = (t_flags *)malloc(sizeof(t_flags))))
			cmn_error();
		(*flags)->count = 0;
		(*flags)->v = 0;
		if (ft_strcmp(str, "-t") == 0)
		{
			(*flags)->count = 1;
			(*flags)->nb = 0;
		}
		else if (ft_strcmp(str, "-v") == 0)
			(*flags)->v = 1;
	}
	return ((*flags)->v + (*flags)->count);
}

void	do_flags(t_stack *a, t_stack *b, t_flags **flags)
{
	if ((*flags)->v)
		display_stacks(a, b);
	else if ((*flags)->count)
		(*flags)->nb++;
}

void	display_stacks(t_stack *a, t_stack *b)
{
	t_stack			*temp;
	t_stack			*temp_b;

	temp = a;
	temp_b = b;
	ft_printf("---------------------------------------------------\n");
	ft_printf(" Stack A :");
	while (temp)
	{
		ft_printf(" |%d|", temp->content);
		temp = temp->next;
	}
	ft_printf("\n Stack B :");
	while (temp_b)
	{
		ft_printf(" |%d|", temp_b->content);
		temp_b = temp_b->next;
	}
	ft_printf("\n---------------------------------------------------\n");
}

void	do_count(t_flags *flags)
{
	if (flags->count)
		ft_printf("== TOTAL MOVES : %d ==\n", flags->nb);
}