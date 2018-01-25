/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:59:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/25 16:03:37 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				min_val(t_stack *a)
{
	int			res;
	t_stack *temp;

	if (!a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	temp = a;
	res = temp->content;
	while (temp)
	{
		if (temp->content > res)
			res = temp->content;
		temp = temp->next;
	}
	return (res);
}

int				min_index(t_stack *a)
{
	int			res;
	int			min;
	t_stack *temp;

	if (!a)
	{
		ft_printf("Error\n");
		exit(1);
	}
	temp = a;
	min = min_val(a);
	res = 0;
	while (temp)
	{
		res++;
		if (temp->content == min)
			return (res);
		temp = temp->next;
	}
	return (-1);
}
