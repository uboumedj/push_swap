/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacknew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:08:12 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/16 15:18:46 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_stack	*ft_stacknew(int content)
{
	t_stack *new;

	if (!(new = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	if (!(new->content = (int)malloc(sizeof(int))))
		return (NULL);
	if (content != 0)
		new->content = content;
	new->next = NULL;
	return (new);
}
