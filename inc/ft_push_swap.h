/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:43:43 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/12 16:15:25 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

#include "../libft/inc/libft.h"

typedef struct		s_pile
{
	int content;
	t_pile *next;
}					t_pile;

void				sa(t_pile *a);
void				sb(t_pile *b);
void				ss(t_pile *a, t_pile *b);

void				pa(t_pile *a, t_pile *b);
void				pb(t_pile *a, t_pile *b);

void				ra(t_pile *a);
void				rb(t_pile *b);
void				rr(t_pile *a, t_pile *b);

#endif
