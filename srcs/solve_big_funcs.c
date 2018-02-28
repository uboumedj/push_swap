/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 13:12:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:04:19 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

int			find_place(t_stack *a, t_stack *b, int index)
{
	int			i;
	int			res;
	int			elem;
	t_stack		*temp;

	i = 0;
	temp = a;
	while (i++ < index)
		temp = temp->next;
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
	int			res;
	t_stack		*temp;

	i = 0;
	temp = b;
	while (i < stack_len(b) - 1 && temp && temp->next)
	{
		if (elem < temp->content && elem > temp->next->content)
			res = i + 1;
		i++;
		temp = temp->next;
	}
	return (res);
}

void		min_steps(t_stack **a, t_stack **b, t_data *data)
{
	int			i;
	int			step_num;

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
}

int			steps(int index, t_stack *a, t_stack *b)
{
	int		steps;
	int		b_middle;
	int		place;

	steps = 0;
	b_middle = 0;
	place = find_place(a, b, index);
	if (index > 0 && index <= stack_len(a) / 2)
		steps += index;
	else if (index != 0)
		steps += stack_len(a) - index;
	steps++;
	b_middle = stack_len(b) / 2;
	if (place <= b_middle)
		steps += place;
	else
		steps += stack_len(b) - place;
	return (steps);
}
