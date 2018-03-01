/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:18:41 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/01 19:43:28 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	do_operations(char *line, t_stack **a, t_stack **b, t_flags **flags)
{
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			ft_strcmp(line, "pa") == 0 ? pa(a, b, flags) : pb(a, b, flags);
		else if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0)
			ft_strcmp(line, "sa") == 0 ? sa(a, b, flags) : sb(a, b, flags);
		else if (ft_strcmp(line, "ss") == 0)
			ss(a, b, flags);
		else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0)
			ft_strcmp(line, "ra") == 0 ? ra(a, b, flags) : rb(a, b, flags);
		else if (ft_strcmp(line, "rr") == 0)
			rr(a, b, flags);
		else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0)
			ft_strcmp(line, "rra") == 0 ? rra(a, b, flags) : rrb(a, b, flags);
		else if (ft_strcmp(line, "rrr") == 0)
			rrr(a, b, flags);
		else
			cmn_error();
		ft_strclr(line);
		free(line);
	}
	if (check_sort(*a))
		do_count(*flags);
	ft_strclr(line);
	free(line);
}
