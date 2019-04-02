/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:17:06 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:11:21 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** Three different error cases with different error outputs and different
** memory release handling.
*/

void	cmn_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	mult_error(t_stack **a, char **args)
{
	ft_stackfree(a);
	ft_strarrayfree(args);
	write(2, "Error : invalid parameters\n", 27);
	exit(1);
}

void	inst_error(t_stack **a, t_stack **b, char *line, t_flags **flags)
{
	free(*flags);
	free(line);
	ft_stackfree(a);
	ft_stackfree(b);
	write(2, "Error : invalid instruction\n", 28);
	exit(1);
}
