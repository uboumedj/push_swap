/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 15:59:04 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/13 17:20:15 by uboumedj         ###   ########.fr       */
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
