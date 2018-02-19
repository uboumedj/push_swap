/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:59:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/17 15:04:32 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int		last_val(t_stack *b)
{
	t_stack *temp;

	temp = b;
	while (temp->next)
		temp = temp->next;
	return (temp->content);
}

int				max_index(t_stack *a)
{
	int			res;
	int			max;
	t_stack		*temp;

	if (!a)
		cmn_error();
	temp = a;
	max = max_val(a);
	res = 0;
	while (temp)
	{
		if (temp->content == max)
			return (res);
		res++;
		temp = temp->next;
	}
	return (-1);
}
