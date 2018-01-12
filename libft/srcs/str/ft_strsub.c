/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:41:40 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 15:16:57 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	if (s != NULL)
	{
		if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		{
			return (NULL);
		}
		i = 0;
		while (i < len)
		{
			res[i] = s[start];
			start++;
			i++;
		}
		res[i] = '\0';
	}
	else
		res = NULL;
	return (res);
}
