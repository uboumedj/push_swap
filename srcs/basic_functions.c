/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:59:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/13 16:35:33 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int				min_val(t_stack *a)
{
	int			res;
	t_stack		*temp;

	if (!a)
		cmn_error();
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

	if (!a)
		cmn_error();
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

int				stack_len(t_stack *a)
{
	int			res;
	t_stack		*temp;

	if (!a)
		cmn_error();
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

int				med_val(t_stack *a)
{
	int			res;
	int			len;
	int			t_res;
	t_stack		*temp;

	if (stack_len(a) < 4)
		cmn_error();
	len = (stack_len(a) / 2);
	res = min_val(a);
	while (len > 0)
	{
		temp = a;
		t_res = max_val(a);
		while (temp)
		{
			if (temp->content < t_res && temp->content > res)
				t_res = temp->content;
			temp = temp->next;
		}
		res = t_res;
		len--;
	}
	return (res);
}
