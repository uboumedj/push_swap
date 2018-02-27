/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:18:41 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/27 19:17:31 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	do_operations(char *line, t_stack **a, t_stack **b)
{
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			ft_strcmp(line, "pa") == 0 ? pa(a, b) : pb(a, b);
		else if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0)
			ft_strcmp(line, "sa") == 0 ? sa(a) : sb(b);
		else if (ft_strcmp(line, "ss") == 0)
			ss(a, b);
		else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0)
			ft_strcmp(line, "ra") == 0 ? ra(a) : rb(b);
		else if (ft_strcmp(line, "rr") == 0)
			rr(a, b);
		else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0)
			ft_strcmp(line, "rra") == 0 ? rra(a) : rrb(b);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(a, b);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		//display_stacks(*a, *b);
		free(line);
	}
}

void	display_stacks(t_stack *a, t_stack *b)
{
	t_stack			*temp;
	t_stack			*temp_b;
	static size_t	i;

	temp = a;
	temp_b = b;
	if (!i)
		i = 1;
	ft_printf("----------------------Turn %d-----------------------\n", i);
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
	i++;
}
