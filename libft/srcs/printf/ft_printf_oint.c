/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 20:42:14 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:22 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

size_t			do_onb(va_list *vlist, int mod, t_printf *handler)
{
	unsigned long long int	res;

	if (mod == 0)
		res = va_arg(*vlist, unsigned int);
	else if (mod == 1)
		res = (unsigned char)va_arg(*vlist, unsigned int);
	else if (mod == 2)
		res = (unsigned short)va_arg(*vlist, unsigned int);
	else if (mod == 3)
		res = va_arg(*vlist, unsigned long int);
	else if (mod == 4)
		res = va_arg(*vlist, unsigned long long int);
	else if (mod == 5)
		res = (uintmax_t)va_arg(*vlist, uintmax_t);
	else if (mod == 6)
		res = (size_t)va_arg(*vlist, size_t);
	else
		return (0);
	return (print_onb((unsigned long long int)res, handler));
}

static int		onb_length(unsigned long long int nb, int *ilen,
													t_printf *handler)
{
	int		res;

	if (nb != 0)
		*ilen = ft_unbrlenbase(nb, 8);
	res = ft_max(handler->prcsn, *ilen);
	if (nb == 0 && handler->prcsn < 0)
		res += 1;
	if (handler->f_shrp && ((nb != 0 && handler->prcsn <= 0)
				|| (nb == 0 && handler->prcsn == 0)))
		res += 1;
	return (res);
}

static void		put_onb(unsigned long long int res)
{
	if (res < 8)
		ft_putchar('0' + res);
	else
	{
		put_onb(res / 8);
		ft_putchar('0' + res % 8);
	}
}

size_t			print_onb(unsigned long long int res, t_printf *handler)
{
	int		ilen;
	int		len;

	if (!handler)
		return (0);
	ilen = 0;
	len = onb_length(res, &ilen, handler);
	if (!(handler->f_min) && len < handler->width)
		ft_putlenchar((handler->f_zero && handler->prcsn == -1) ?
			'0' : ' ', handler->width - len);
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	else if (handler->f_shrp && (res != 0 || handler->prcsn == 0))
		ft_putchar('0');
	if (res != 0 || handler->prcsn == -1)
		put_onb(res);
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
