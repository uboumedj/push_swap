/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrayfree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:09:50 by uboumedj          #+#    #+#             */
/*   Updated: 2018/02/28 17:19:55 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_strarrayfree(char **strs)
{
	char *temp;

	while (strs)
	{
		temp = *strs;
		strs = strs + 1;
		free(temp);
	}
	free(strs);
}
