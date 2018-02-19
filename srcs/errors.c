/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:13:37 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/16 06:02:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_push_swap.h"

void	mem_error(void)
{
	ft_printf("memory error !\n");
	exit(1);
}

void	cmn_error(void)
{
	ft_printf("Error !\n");
	exit(1);
}
