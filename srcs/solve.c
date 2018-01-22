/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:18:09 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/22 16:28:27 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void solve(t_stack *a, t_stack *b)
{
	int		len;

	if (!(len = ft_stacklen(a)))
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (len < 6)
		ft_printf("solve small len");
	else
		ft_printf("solve big len");
}
