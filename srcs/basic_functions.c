/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:59:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:09:45 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				min_val(t_stack *a)
{
	int			res;
	t_stack		*temp;

	temp = a;
	res = temp->content;
	while (temp)
	{
		if (temp->content < res)
			res = temp->content;
		temp = temp->next;
	}
	return (res);
}

int				min_index(t_stack *a)
{
	int			res;
	int			min;
	t_stack		*temp;

	temp = a;
	min = min_val(a);
	res = 0;
	while (temp)
	{
		if (temp->content == min)
			return (res);
		res++;
		temp = temp->next;
	}
	return (-1);
}

int				stack_len(t_stack *a)
{
	int			res;
	t_stack		*temp;

	if (!a)
		return (0);
	res = 0;
	temp = a;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return (res);
}

int				max_val(t_stack *a)
{
	int			res;
	t_stack		*temp;

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
