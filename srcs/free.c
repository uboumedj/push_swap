/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:13:53 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 15:14:26 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void			freedom(t_stack *a, t_stack *b, t_flags *flags, char **args)
{
	ft_stackfree(&a);
	ft_stackfree(&b);
	free(flags);
	ft_strarrayfree(args);
}
