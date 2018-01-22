/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacklen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:23:15 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/22 16:25:15 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int		ft_stacklen(t_stack *stack)
{
	int			res;
	t_stack *temp;

	res = 0;
	temp = stack;
	while (temp)
	{
		res++;
		temp = temp->next;
	}
	return (res);
}
