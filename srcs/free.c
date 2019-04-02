/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 15:13:53 by uboumedj          #+#    #+#             */
/*   Updated: 2018/03/02 17:11:47 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

/*
** freedom function is called to free all the malloc'ed memory before exiting
** the program.
*/

void			freedom(t_stack *a, t_stack *b, t_flags *flags, char **args)
{
	ft_stackfree(&a);
	ft_stackfree(&b);
	free(flags);
	ft_strarrayfree(args);
}
