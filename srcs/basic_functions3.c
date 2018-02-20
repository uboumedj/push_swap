/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:12:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/20 01:55:41 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int			find_place(t_stack *a, t_stack *b, int index)
{
	int			i;
	int			res;
	int			elem;
	t_stack *temp;

	i = 0;
	temp = a;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	elem = temp->content;
	i = 0;
	res = -1;
	if (stack_len(b) == 0)
		return (0);
	else if (elem < min_val(b))
		return (max_index(b));
	else if (elem > max_val(b))
		return (max_index(b));
	else
		res = check_location(b, elem);
	return (res);
}

int			check_location(t_stack *b, int elem)
{
	int			i;
	int			min_dif;
	int			res;
	t_stack *temp;

	i = 0;
	min_dif = 2147483647;
	temp = b;
	if (check_middle(b, elem))
	{
		res = 0;
		min_dif = ft_abs(temp->content - last_val(temp));
	}
	while (i < stack_len(b) - 1 && temp && temp->next)
	{
		if ((elem > temp->content && elem < temp->next->content) ||
				(elem < temp->content && elem > temp->next->content))
		{
			if (ft_abs(temp->next->content - temp->content) <
					min_dif && (res = i + 1))
				min_dif = ft_abs(temp->next->content - temp->content);
		}
		i++;
		temp = temp->next;
	}
	return (res);
}

int			check_middle(t_stack *b, int elem)
{
	int		first;
	int		last;

	first = b->content;
	last = last_val(b);
	if ((elem > first && elem < last) || (elem < first && elem > last))
		return (1);
	else
		return (0);
}

int			min_steps(t_stack **a, t_stack **b)
{
	int			i;
	int			step_num;
	t_data	*data;

	i = 0;
	data->min_steps = 2147483647;
	data->min_index = 2147483647;
	while (i < stack_len(*a))
	{
		step_num = steps(i, *a, *b);
		if (step_num < data->min_steps)
		{
			data->min_steps = step_num;
			data->min_index = i;
		}
		i++;
	}
	data->place = find_place(*a, *b, data->min_index);
	rotations(a, b, data);
	return (data->min_index);
}

int			steps(int index, t_stack *a, t_stack *b)
{
	int		steps;
	int		b_middle;
	int		place;

	steps = 0;
	b_middle = 0;
	place = find_place(a, b, index);
	if (index == 0)
		steps = 0;
	else if (index <= stack_len(a) / 2)
		steps += index;
	else
		steps += stack_len(a) - index;
	steps++;
	b_middle = stack_len(b) / 2;
	if (place <= b_middle)
		steps += place;
	else
		steps += stack_len(b) - place;
	return (steps);
}
