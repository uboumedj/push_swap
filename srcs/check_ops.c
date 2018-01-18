/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:18:41 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/18 17:17:28 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	do_operations(char *line, t_stack **a, t_stack **b)
{
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp(line, "pa") == 0)
			pa(*a, *b);
		else if (ft_strcmp(line, "pb") == 0)
			pb(*a, *b);
		else if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0)
			ft_strcmp(line, "sa") ? sa(*a) : sb(*b);
		else if (ft_strcmp(line, "ss") == 0)
			ss(*a, *b);
		else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0)
			ft_strcmp(line, "ra") ? ra(*a) : rb(*b);
		else if (ft_strcmp(line, "rr") == 0)
			rr(*a, *b);
		else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0)
			ft_strcmp(line, "rra") ? rra(*a) : rrb(*b);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(*a, *b);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
}
