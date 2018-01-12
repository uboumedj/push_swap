/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:36:23 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:22 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t		strparse(const char *str, va_list *vlist)
{
	size_t		len;
	char		*tmp;
	char		*start;

	len = 0;
	tmp = (char *)str;
	start = tmp;
	while (*tmp != '\0')
	{
		if (*tmp != '\0' && *tmp != '%')
		{
			tmp++;
			len++;
		}
		else if (*tmp == '%')
		{
			ft_putlenstr(start, tmp - start);
			len += do_flag(&tmp, vlist);
			start = tmp;
		}
	}
	ft_putlenstr(start, tmp - start);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list	vlist;
	size_t	len;

	len = 0;
	if (format)
	{
		va_start(vlist, format);
		len = strparse(format, &vlist);
		va_end(vlist);
	}
	return (len);
}
