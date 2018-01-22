/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:43:43 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/22 16:02:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H

# define FT_PUSH_SWAP_H

# include "../libft/inc/libft.h"

/*
** ----------------------Pile manipulation functions------------------------
*/

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);

void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);

void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

/*
** -------------------------Common functions--------------------------------
*/

void				get_numbers(t_stack **a, int argc, char **argv);
void				init_list(t_stack **a, int argc, char **argv);
int					check_valid_nb(long long int nb, t_stack *a);
int					check_valid_args(int argc, char **argv);

/*
** -----------------------------Push_swap-----------------------------------
*/



/*
** ------------------------------Checker------------------------------------
*/

int					check_sort(t_stack *a);
void				do_operations(char *line, t_stack **a, t_stack **b);

#endif
